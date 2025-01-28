import argparse
import requests
from bs4 import BeautifulSoup
import whois
import shodan
from googlesearch import search
import csv
import tweepy
import json


# ==== CONFIGURATION: API KEYS ====
SHODAN_API_KEY = "your_shodan_api_key"
HIBP_API_KEY = "your_hibp_api_key"
TWITTER_API_KEY = "your_twitter_api_key"
TWITTER_API_SECRET = "your_twitter_api_secret"
TWITTER_ACCESS_TOKEN = "your_twitter_access_token"
TWITTER_ACCESS_SECRET = "your_twitter_access_secret"


# ==== FEATURE: Subdomain Enumeration ====
def get_subdomains(domain):
    url = f"https://crt.sh/?q={domain}&output=json"
    try:
        response = requests.get(url)
        response.raise_for_status()
        data = response.json()
        subdomains = set()
        for entry in data:
            subdomains.update(entry['name_value'].split("\n"))
        return list(subdomains)
    except Exception as e:
        return f"Error during subdomain enumeration: {e}"


# ==== FEATURE: WHOIS Lookup ====

def whois_lookup(domain):
    """
    Perform a WHOIS lookup using the 'whois' Python library. 
    If the library fails, use the system's WHOIS command as a fallback.
    """
    try:
        # Try using the 'whois' Python library
        w = whois.whois(domain)
        return {
            "Domain Name": w.domain_name,
            "Registrar": w.registrar,
            "Creation Date": w.creation_date,
            "Expiration Date": w.expiration_date,
            "Name Servers": w.name_servers,
        }
    except Exception as e:
        # If the Python library fails, fall back to the system WHOIS command
        try:
            print(f"Python WHOIS library failed, falling back to system WHOIS: {e}")
            result = subprocess.check_output(['whois', domain], universal_newlines=True)
            return {"Raw WHOIS Data": result}
        except Exception as cmd_error:
            return f"Error during WHOIS lookup using system command: {cmd_error}"


# ==== FEATURE: Shodan Lookup ====
def shodan_lookup(ip):
    try:
        api = shodan.Shodan(SHODAN_API_KEY)
        host = api.host(ip)
        return {
            "IP": host["ip_str"],
            "Organization": host.get("org", "N/A"),
            "OS": host.get("os", "N/A"),
            "Open Ports": host["ports"],
        }
    except shodan.APIError as e:
        return f"Error during Shodan lookup: {e}"


# ==== FEATURE: Social Media Scraper (Twitter) ====
def get_tweets(username, count=5):
    try:
        auth = tweepy.OAuthHandler(TWITTER_API_KEY, TWITTER_API_SECRET)
        auth.set_access_token(TWITTER_ACCESS_TOKEN, TWITTER_ACCESS_SECRET)
        api = tweepy.API(auth)

        tweets = api.user_timeline(screen_name=username, count=count, tweet_mode="extended")
        return [tweet.full_text for tweet in tweets]
    except Exception as e:
        return f"Error during Twitter scraping: {e}"


# ==== FEATURE: Breach Checking (HaveIBeenPwned) ====
def check_breach(email):
    url = f"https://haveibeenpwned.com/api/v3/breachedaccount/{email}"
    headers = {
        "hibp-api-key": HIBP_API_KEY,
        "user-agent": "OSINT-Tool"
    }
    try:
        response = requests.get(url, headers=headers)
        if response.status_code == 200:
            return response.json()
        elif response.status_code == 404:
            return "No breach found."
        else:
            return f"Error: {response.status_code}"
    except Exception as e:
        return f"Error during breach check: {e}"


# ==== FEATURE: Google Dorking ====
def google_dork(query, num_results=5):
    try:
        results = []
        for result in search(query, num=num_results, stop=num_results):
            results.append(result)
        return results
    except Exception as e:
        return f"Error during Google Dorking: {e}"


# ==== FEATURE: Save Results to CSV ====
def save_to_csv(data, filename="output.csv"):
    try:
        with open(filename, mode="w", newline="") as file:
            writer = csv.writer(file)
            writer.writerow(["Feature", "Results"])
            for key, value in data.items():
                writer.writerow([key, json.dumps(value)])
        print(f"[+] Results saved to {filename}")
    except Exception as e:
        print(f"Error saving results to CSV: {e}")


# ==== MAIN CLI INTERFACE ====

# Main CLI Interface
def main():
    parser = argparse.ArgumentParser(description="OSINT Tool for Recon and Information Gathering")
    parser.add_argument("--domain", help="Perform subdomain enumeration and WHOIS lookup")
    parser.add_argument("--ip", help="Perform Shodan lookup for an IP address")
    parser.add_argument("--tweets", help="Get recent tweets from a Twitter username")
    parser.add_argument("--breach", help="Check if an email has been in a breach")
    parser.add_argument("--dork", help="Perform Google Dorking with a query")
    parser.add_argument("--output", help="Save results to a CSV file", action="store_true")

    args = parser.parse_args()
    results = {}

    if args.domain:
        print(f"[*] Gathering information for domain: {args.domain}")
        results["Subdomains"] = get_subdomains(args.domain)
        results["WHOIS"] = whois_lookup(args.domain)

    if args.ip:
        print(f"[*] Gathering Shodan data for IP: {args.ip}")
        results["Shodan"] = shodan_lookup(args.ip)

    if args.tweets:
        print(f"[*] Fetching tweets for user: {args.tweets}")
        results["Tweets"] = get_tweets(args.tweets)

    if args.breach:
        print(f"[*] Checking breach status for email: {args.breach}")
        results["Breach"] = check_breach(args.breach)

    if args.dork:
        print(f"[*] Performing Google Dorking: {args.dork}")
        results["Google Dork"] = google_dork(args.dork)

    if args.output:
        save_to_csv(results)

    # Print results
    print("\n[+] Final Results:")
    for feature, data in results.items():
        print(f"{feature}:\n{data}\n")


if __name__ == "__main__":
    main()
