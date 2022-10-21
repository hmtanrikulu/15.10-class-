#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
class database {
	class user {
	private:
		string username;
		string lastname;
		tm birthdate;
		int id;
		int basesalary;
		int workexp;
		int sectoyear(int x) {
			int year = 60 * 60 * 24 * 365 + 6;
			return (int)(x / year);
		}
	public:
		string name() {
			return this->username;
		}
		string lastName() {
			return this->lastname;
		}
		int age() {
			time_t tmp = mktime(&this->birthdate);
			auto birthdate = chrono::system_clock::from_time_t(tmp);
			auto curr = chrono::system_clock::now();
			auto age_diff = (curr - birthdate);
			auto age_seconds = chrono::duration_cast<chrono::seconds>(age_diff);
			return this->sectoyear(age_seconds.count());
		}
		user( // ayný isimde "user"  yazýnca constructer
			string username,
			string lastname,
			int id,
			int basesalary,
			int workexp,
			int day,
			int month,
			int year
		) {
			this->birthdate = { 0 };
			this->username = username;
			this->lastname = lastname;
			this->birthdate.tm_year = year - 1900;
			this->birthdate.tm_mon = month - 1;
			this->birthdate.tm_mday = day;
			this->id = id;
			this->basesalary = basesalary;
			this->workexp = workexp;
		}
	};
	vector <user> users;
	bool doesUserExist(string n, string ln) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].name() == n && users[i].lastName() == ln) {
				return true;
			}
		}
		return false;
	}
public:
	void createUser(
		string username,
		string lastname,
		int basesalary,
		int workexp,
		int day,
		int month,
		int year) {
		if (this->doesUserExist(username, lastname)) {
			int id = users.size() + 1; // user sayýsý na gore id verme
			user tmp(
				username, lastname, id, basesalary, workexp, day, month, year
			);
			users.push_back(tmp);
		}
	}
};
//struct user {
//	string username;
//	string lastname;
//	string birthdate;
//	int id;
//	int basesalary;
//	int workexp;
//}user1, user2;
int main() {
	database db;
	db.createUser(
		"can",
		"arikan",
		20,
		1,
		14,
		3,
		1998
	);
	return 0;
}