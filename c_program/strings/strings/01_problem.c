/*WAP to make a user login system, where user first need to set their username and 
password; after setting the users username and password, now user have to login 
to the system. To login, user needs to enter their username and password, login is 
successful when both username and password entered is correct, unsuccessful 
when one of them is incorrect. In case of incorrect credentials, user can try upto 3 
times.*/ 
//Bijaya Kumal
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int m_main();
void systemlogin(bool a, int i){
	if(a){
		puts("Access Granted");
	}else{
		if(i<=3){
			puts("Access denied");
			i++;
			m_main(i);
		}
	}
}
int m_main(int i){
	char username[9],password[12];
	puts("Enter the username");
	fgets(username,9,stdin);
	puts("Enter the password");
	fgets(password,12,stdin);
	systemlogin((strcmp(username,"admin00\n"))==0 && (strcmp(password,"softwarica\n")==0),i);
}
int main(){
	m_main(1);
}
//Bijaya Kumal
