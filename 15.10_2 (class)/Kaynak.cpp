#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;
class user {
private:
	string username;
	string lastname;
	string birthdate;
	int id;
	int basesalary;
	int workexp;
public:
	int age() {
		this -> birthdate;

		time_t end_time = chrono::system_clock::to_time_t(chrono::system_clock::now());
		end_time;
	}
}user1 , user2;
//struct user {
//	string username;
//	string lastname;
//	string birthdate;
//	int id;
//	int basesalary;
//	int workexp;
//}user1, user2;
int main() {
	user1.username = "can";
	return 0;
}