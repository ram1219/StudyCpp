#include <stdio.h>

#define MYSQLUSER "root"					// 유저이름
#define MYSQLPASSWORD "mysql_p@ssw0rd"		// 비밀번호
#define MYSQLIP "localhost"					// 연결할 ip

class DBQuery {
private:
	static int hCon;
	int nResult;
public:
	DBQuery() {}
	static void DBConnect(const char* Servr, const char* ID, const char* Pass);
	static void DBDisConnect();
	bool RunQuery(const char* SQL);
};

int DBQuery::hCon;

void DBQuery::DBConnect(const char* Servr, const char* ID, const char* Pass) {
	//MYSQL* hCon = mysql_init(NULL);
	//mysql_real_connect(&hCon, Server, ID, Pass, NULL, 0, NULL, 0);
	hCon = 1234;
	puts("연결성공");
}

void DBQuery::DBDisConnect() {
	// 접속해제
	//mysql_close(hCon);
	hCon == NULL;
	puts("연결해제");
}

bool DBQuery::RunQuery(const char* SQL) {
	//mysql_query(hCon, SQL);
	puts(SQL);
	return true;
}

int main() {
	//DBQuery* dbcon = new DBQuery();
	//DBQUERY dbcon2();


	//DBQuery::DBConnect("localhost", "root", "mysql_p@ssw0rd");
	DBQuery::DBConnect(MYSQLIP, MYSQLUSER, MYSQLPASSWORD);
	DBQuery con1, con2, con3;
	//필요한 DB쿼리 실행
	con1.RunQuery("SELECT * FROM usertbl WHERE userID = 'KBS';");

	DBQuery::DBDisConnect();

	return 0;
}