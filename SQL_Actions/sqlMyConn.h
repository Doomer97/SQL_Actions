#pragma once
using namespace MySql::Data::MySqlClient;
using namespace System;

ref class sqlConn
{
private:
	String^ username;
	String^ password;
	String^ host = "dspai.kastoria.teiwm.gr";
	String^ constring;

	MySqlConnection^ condb;
public:
	sqlConn() {

	};//Default
	sqlConn(String^ uname, String^ pass) {
		setUsername(uname);
		setPassword(pass);
	};//constructor

	~sqlConn() {
		username = "\0";
		password = "\0";
		constring = "\0";
		condb=nullptr;
		//System::Windows::Forms::MessageBox::Show("Im the destructor!");
	};
	String^ getUsername() {
		return username;
	}
	String^ getHost() {
		return host;
	}
	MySqlConnection^ getConnection() {
		return condb;
	}
	void setUsername(String^ username) {
		this->username = username;
	}
	void setPassword(String^ password) {
		this->password = password;
	}
	void setCondb(MySqlConnection^ condb) {
		this->condb = condb;
	}
	MySqlConnection^ Connection() {
		constring = L"datasource=" + host + "; port=3306; username=" + username + "; password=" + password;
		return condb=gcnew MySqlConnection(constring);

	}
};