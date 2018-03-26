// A small example program using SQLite with C++
#include <iostream>
#include <sqlite3.h>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	int i;
	for(i=0; i<argc; i++)
	{
		cout<<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL")<<"\n";
	}
	cout<<"\n";
	return 0;
}
// seelct all data from table
void getTableData(sqlite3* db)
{
    sqlite3_stmt *statement;

    const char *query = "select * from myTable";
    if ( sqlite3_prepare(db, query, -1, &statement, 0 ) == SQLITE_OK )
    {
        int ctotal = sqlite3_column_count(statement);
        int res = 0;

        while ( 1 )
        {
            res = sqlite3_step(statement);

            if ( res == SQLITE_ROW )
            {
                for ( int i = 0; i < ctotal; i++ )
                {
                    string s = (char*)sqlite3_column_text(statement, i);
                    // print or format the output as you want
                    cout << s << " " ;
                }
                cout << endl;
            }

            if ( res == SQLITE_DONE || res==SQLITE_ERROR)
            {
                cout << "done " << endl;
                break;
            }
        }
    }
}

int main()
{
	const int STATEMENTS = 8;
	sqlite3 *db;
	char *zErrMsg = 0;
	const char *pSQL[STATEMENTS];
	int rc;

	rc = sqlite3_open("familyGuy.db", &db);

	if( rc )
	{
		cout<<"Can't open database: "<<sqlite3_errmsg(db)<<"\n";
	}
	else
	{
		cout<<"Open database successfully\n\n";
	}

	pSQL[0] = "create table myTable (FirstName TEXT, LastName TEXT, Age smallint, Hometown TEXT, Job TEXT)";

	pSQL[1] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Peter', 'Griffin', 41, 'Quahog', 'Brewery')";

	pSQL[2] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Lois', 'Griffin', 40, 'Newport', 'Piano Teacher')";

	pSQL[3] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Joseph', 'Swanson', 39, 'Quahog', 'Police Officer')";

	pSQL[4] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Glenn', 'Quagmire', 41, 'Quahog', 'Pilot')";

	pSQL[5] = "select * from myTable";

	// pSQL[6] = "delete from myTable";
	//
	// pSQL[7] = "drop table myTable";
	getTableData(db);

	// for(int i = 0; i < STATEMENTS; i++)
	// {
	// 	rc = sqlite3_exec(db, pSQL[i], callback, 0, &zErrMsg);
	// 	if( rc!=SQLITE_OK )
	// 	{
	// 		cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
	// 		sqlite3_free(zErrMsg);
	// 		break;
	// 	}
	// }

	sqlite3_close(db);

	return 0;
}
