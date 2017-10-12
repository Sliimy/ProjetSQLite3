#include <stdio.h>
#include <sqlite3.h>
#include <string>
#include <iostream>
#include "gestionDB.h"


// AJOUT FOREIGN KEY POUR LES SORTIES
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    printf("Je suis dedans\n");
    rc = sqlite3_open("mainP.db", &db);
    /*valeurs testées :
     * myPLCDB.db
     * myPLCDB
     * */
    printf("Je suis dedans 2\n");
    char nameTable[]="table1";
    createNewTable( nameTable,3,db);


    sqlite3_close(db);


    printf("Hello, World!\n");
    return 0;
}




/* int CreateTableSQL()
{
    char *sql;



    //création du fichier de stockage de la database, necessaire une seul fois
     SQLiteConnection.C("myPLCEntries.sqlite");
    //création et initialisation de la connexion
    //SQLiteConnection m_dbConnection = new SQLiteConnection();
    //m_dbConnection = new SQLiteConnection("Data Source=myPLCEntries.sqlite;Version=3;");
    //ouverture de la connexion
    //m_dbConnection.Open();
    //création de la request SQL pour la creation de la table Entries
    //string sql = "CREATE TABLE Entries (Pin1(20), Pin2(20), Pin3(20), Pin4(20))";
    //création de la commande
    //SQLiteCommand command = new SQLiteCommand(sql, m_dbConnection);
    //éxecution de la commande, il existe plusieurs façon d'executer la commande en fonction des types d'info retourné
    //command.ExecuteNonQuery();

    //fermeture de la connexion
    //m_dbConnection.Close();
    return 0;
}

int ajoutDataDB()
{
    //A ADAPTER ENSUITE EN PASSANT UN TABLEAU EN ENTREE DE LA FCT

    //création et initialisation de la connexion
    SQLiteConnection m_dbConnection;
    m_dbConnection = new SQLiteConnection("Data Source=myPLCEntries.sqlite;Version=3;");
    //ouverture de la connexion
    m_dbConnection.Open();

    sql = "insert into Entries (Pin1, Pin2, Pin3, Pin4) values ('0', '1', '1', '0')";
    command = new SQLiteCommand(sql, m_dbConnection);
    command.ExecuteNonQuery();
    //fermeture de la connexion
    m_dbConnection.Close();
}
 */