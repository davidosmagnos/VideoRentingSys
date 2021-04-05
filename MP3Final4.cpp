#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <list>
#include <queue>
#include <stack>
#include <windows.h>// for Sleep and system
using namespace std;
struct info{//video details
	string name;
	string genre;
	string filename;
	string prod;
	int id;
	int copies;
};
struct custinfo{//customer details
		int id;
		string name;
		string ad;
};
struct rentVids{//video details of rented videos
 int custID;
 int vID;
 string title;
};
class vids{//video ADT
	private:
		list<info> vd;//holds vids info
		list<info>::iterator it;//iterator
	public:
		void insert(info inf);//insert new vids
		void display();//display all movies
		void displayMovie(int);//shoes one certain movie
		void vidAvailability(int);//checks video availability
		string rent (int id, int id1);// rents video returns name of movie
		void write();//writes in file
		int size();		//returns size of queue
		void retrieve();//reads from file
		void returnvid(int id,int id1);//returns vid decrements copies
};
class custs{//customer ADT
	private:
	queue<custinfo> ci;//holds customer infornation
	queue<custinfo> temp;//temporarily holds info
	public:
		void add(custinfo cust);//adds customer
		void show(int id);//shows customer details
		void retrieve();//retrieves from file
		int size();//returns size
		void writecust();//writes to file
};
class rented : protected custs{//rented videos ADT
	private:
		stack<rentVids> rm;//stores all rented videos
		list<rentVids> liv;//stores retained videos
		stack<rentVids> temp1;//temporary holder for rented videos
		list<rentVids>::iterator it1;//iterator for list
	public:
		void writerent();// writes rented vids in file
		void accept(string, int, int);//passes information from vids adt to rented adt
		void retrieverent();//reads information from file
		void showrented(int id);//displays rented videos
		void removee(int id,int id1);//remove from list of rented movies
		int returnn(int id);//returns movie
};
int main(){
	info det;
	rented Rented;
	vids Vids; char yn,yn1;
	custs Custs; custinfo det1;
	int choice,op;
	Vids.retrieve();
	Custs.retrieve();
	int c_s= Custs.size();
	int s=Vids.size();
	Rented.retrieverent();
	bool check=true;
	
	do{
		mm:
		system("cls");
		cout <<"[1]New Video" << endl
			 <<"[2]Rent Video" << endl
			 <<"[3]Return Video" << endl
			 <<"[4]Display Video Details" << endl
			 <<"[5]Display All Videos" << endl
			 <<"[6]Check Video Availability" << endl
			 <<"[7]Customer" << endl
			 <<"[8]Exit" << endl;
			 cin >> choice;
			 switch(choice){
			 	case 1:{
			 		do{
			 		system("cls");
			 		s++;
			 		det.id = s;
					cout << "<< New Video >>" << endl << endl;
					cout << "ID:" << det.id << endl; 
					cin.ignore();
					cout << "Title:"; getline(cin, det.name);
					cout << "Genre:"; getline(cin, det.genre);
					cout << "Production:"; getline(cin,det.prod);
					cout << "Image Filename:"; getline(cin, det.filename);
					cout << "Number of Copies:"; cin >> det.copies;
					Vids.insert(det);
					cout << "Return to menu?"; cin >> yn;
				}while(toupper(yn)!='Y');
				 }break;
				 case 2:{
				 	do{
				 		system("cls");
				 		cout << "<< Rent Video >>" << endl << endl;
				 		try{
				 			cout << "Enter Customer ID: "; cin >> det1.id;
				 			Custs.show(det1.id);
				 			try{
				 				cout << "Enter Video id: ", cin >> det.id;
				 				Rented.accept(Vids.rent(det1.id, det.id),det1.id,det.id);
					 			cout << "Return to menu?"; cin >> yn;
							 }catch(int x){
							 	cerr << "Error " << x << ": Video Not found..." << endl;
							 	cout << "Returning Main menu..." << endl;
						 		Sleep(1000);
						 		yn='Y';
							 }
						 }catch(int x){
						 	cerr << "Error " <<  x << ": Customer not found..." << endl;
						 	cout << "Returning Main menu..." << endl;
						 	Sleep(1000);
						 	yn='Y';
						 }
					 }while(toupper(yn)!='Y');
				 }break;
				 case 3:{
				 	do{
				 		system("cls");
				 		cout << "<< Return Video >>" << endl << endl;	
				 	try{
				 		cout << "Customer ID: "; cin >> det1.id;
				 		Custs.show(det1.id);
				 		try{
				 		cout << endl << "Videos Rented by customer:" << endl;
				 		Rented.showrented(det1.id);
				 		cout << "ID of Video to return: "; cin >> det.id;
				 		Vids.returnvid(det.id,det1.id);
				 		Rented.removee(det.id,det1.id);
				 		cout << "Return to menu?"; cin >> yn;
						 }catch(int x){
						 	cerr << "Error " << x << ": No videos rented!" << endl; 
						 	cout << "Returning Main menu..." << endl;
						 	Sleep(1000);
						 	yn='Y';
						 }
					 }catch(int x){
					 	cerr << "Error " << x << ": Customer not found!" << endl;
					 		cout << "Returning Main menu..." << endl;
						 	Sleep(1000);
					 		yn='Y';
					 }
				 }while(toupper(yn)!='Y');
				 }break;
				 case 4:{
				 	do{
				 	system("cls");
				 	cout << " << Movie Details >> \n";
				 	cout << "Movie ID: ";
				 	try{
				 		cin >> det.id;
				 		Vids.displayMovie(det.id);
						cout << "Return to menu?"; cin >> yn;
					 }catch(int x){
					 	cerr << "Error " << x << ": Video not found..." << endl;
					 	cout << "Returning Main menu..." << endl;
						Sleep(1000);
					 	yn='Y';
					 }
					 }while(toupper(yn)!='Y');
				 }break;
				 case 5:{
				 	do{
				 	system("cls");
				 	cout << " << Show All Video >> \n";
				 	try{
				 	Vids.display();
					 cout << "Return to menu?"; cin >> yn;
					 }catch(int x){
					 	cerr << "Error " << x << ": Archive Empty..." << endl;
					 	cout << "Returning Main menu..." << endl;
						Sleep(1000);
					 	yn='Y';
					 }
					 }while(toupper(yn)!='Y');
				 }break;
				 case 6:{
				 	do{
				 		system("cls");
					cout << " << Video Availability >> \n";
					try{
						cout << "Movie ID: "; cin >> det.id;
						Vids.vidAvailability(det.id);	
					 	cout << "Return to menu?"; cin >> yn;
					}catch(int x){
						cerr << "Error " << x << ": Video not found..." <<endl;
						cout << "Returning Main menu..." << endl;
						Sleep(1000);
					 	yn='Y';
					}
					 }while(toupper(yn)!='Y');
				 }break;
				 case 7:{
					do{
				 		system("cls");
					cout <<"[1]Add New Customer" << endl
			 			 <<"[2]Show Customer Details" << endl
			 		 	 <<"[3]Videos Rented" << endl
						 <<"[4]Back to main menu" << endl;
			 			 cin >> op;
			 			 switch(op){
			 			 	case 1:{
			 			 		do{
			 			 			system("cls");
			 			 			cout << " << Add New Customer >> \n";
			 			 			c_s++;
			 			 			det1.id = c_s;
			 			 			cout << "<< Add New Customer >>" << endl;
			 			 			cout << "Customer ID: " <<  det1.id << endl;
			 			 			cin.ignore();
			 			 			cout << "Name: "; getline(cin,det1.name);
			 			 			cout << "Address: "; getline(cin ,det1.ad);
			 			 			Custs.add(det1);
									cout << "Return to Customer Maintenance"; cin >> yn1;
								  }while(toupper(yn1)!='Y');
							  }break;
							case 2: {
								do{
									system("cls");
									cout << " << Show Customer Details >> \n";
								try{
									cout << "Enter id: ",cin >> det.id;
									Custs.show(det.id);
								  cout << "Return to Customer Maintenance?"; cin >> yn1;
								}catch(int x){
									cerr << "Error " << x << ": Customer Not found..." << endl;
							 		cout << "Returning to Customer Maintenance..." << endl;
						 			Sleep(1000);
						 			yn1='Y';
								}
								}while(toupper(yn1)!='Y');
								
								}break;
							case 3: {
								do{
									system("cls");
									cout << " << Videos Rented >> \n";
									try{
									cout << "Customer ID: ",cin >> det1.id;
									Rented.showrented(det1.id);
									cout << "Return to Customer Maintenance?"; cin >> yn1;
									}catch(int x){
										cout << "Error " << x << ": Video not Found..." << endl;
										cout << "Returning to Customer Maintenance..." << endl;
						 				Sleep(1000);
						 				yn1='Y';
									}
								}while(toupper(yn1)!='Y');
								break;
							}
							case 4: {
								goto mm;
							}
						}
				 	}while(toupper(yn1)!='N');
					 }
					 break;
				 case 8:{
					Vids.write();
					Rented.writerent();
					Custs.writecust();
					return 0;
				 }
			 }
	}while(toupper(yn)!='N');
}
void vids::insert(info inf){
	vd.push_back(inf);
}
void vids::display(){
		if(vd.empty()){
			throw 104;
		}
			for(it=vd.begin(); it != vd.end();it++){
			cout << "ID: "<< it->id << endl;
			cout << "Title: "<< it->name << endl;
			cout << "Genre: "<< it->genre << endl;
			cout <<"Production: "<< it->prod << endl;
			cout <<"Filename: "<< it->filename << endl;
			cout <<"Number of Copies: "<< it->copies << endl << endl;
		}
}
void vids::displayMovie(int id){
	bool found = false;
	ofstream out("vid_det.txt");
	for(it=vd.begin(); it!=vd.end();it++){
		if(it->id== id){
			found = true;
			cout << "Title: "<< it->name << endl;
			cout << "Genre: "<< it->genre << endl;
			cout <<"Production: "<< it->prod << endl;
			cout <<"Filename: "<< it->filename << endl;
			cout <<"Number of Copies: "<< it->copies << endl << endl;
			out << it->id << endl;
			out << it->name << endl;
			out << it->genre << endl;
			out << it->prod << endl;
			out << it->filename << endl;
			out << it->copies;
			out.close();
			system("disp.exe");
			break;
		}
		
	}
	if(!found){
		throw 103;
	}

}
void vids::vidAvailability(int id){
	bool found = false;
	for(it=vd.begin(); it!=vd.end();it++){
		if(it->id== id){
			found = true;
			cout << "Title: "<< it->name << endl;
			cout << "Genre: "<< it->genre << endl;
			cout <<"Production: "<< it->prod << endl;
			cout <<"Number of Copies: "<< it->copies << endl << endl;
			if(it->copies >=1)
			cout <<"Available..." << endl << endl;
			else 
			cout << "Not Available.."<< endl << endl;
		}
	}
	if(!found){
		throw 105;
	}
}
int vids::size(){
	if(vd.empty()){
		return 0;
	}else{
		return vd.size();
	}
}
int custs::size(){
	if(ci.empty()){
		return 0;
	}else{
		return ci.size();
	}
}
void vids::write(){
	ofstream out("Videos.txt");
		for(it=vd.begin();it!=vd.end();it++){
			out << endl << it->id << endl;
			out << it->name << endl;
			out << it->genre << endl;
			out << it->prod << endl;
			out << it->filename << endl;
			out << it->copies;
		}
	out.close();
}
void vids::retrieve(){
	ifstream in("Videos.txt");
	info ret;
		while(!in.eof()){
		in >> ret.id;
		in.ignore();
		getline(in,ret.name);
		getline(in,ret.genre);
		getline(in,ret.prod);
		getline(in,ret.filename);
		in >> ret.copies;
		if(ret.copies!=0)
		vd.push_back(ret);
	}

}
string vids::rent(int id, int id1){
	bool found = false;
	for(it=vd.begin(); it!=vd.end();it++){
		if(it->id== id1){
			if(it->copies!=0){
				found = true;
				cout <<"Title: "<< it->name << endl ;
				cout <<"Number of copies: "<< it->copies << endl;
				it->copies--;
				break;
			}
			}
		}
		if(!found){
			throw 102;
		}
		return it->name;
	}
void custs::retrieve(){
	ifstream in("customer.txt");
	custinfo cus;
	while(!in.eof()){
		in >> cus.id;
		in.ignore();
		getline(in, cus.name);
		getline(in, cus.ad);
		if(cus.name!="")
		ci.push(cus);
	}
	temp = ci;
}
void custs::show(int id){
	bool found = false;
	while(!ci.empty()){
		if(id == ci.front().id){
			found = true;
			cout << ci.front().name << endl;
			cout << ci.front().ad << endl;
		}
		ci.pop();
	}
	while(!ci.empty()){
		ci.pop();
	}
	ci = temp;
	if(!found){
		throw 100;
	}
	}
void rented::accept(string ti, int cuid, int vId){
	rentVids rv;
	rv.title = ti;
	rv.custID = cuid;
	rv.vID=vId;
	rm.push(rv);
}
void rented::writerent(){
	ofstream out("rented_vids.txt");	
	while(!rm.empty()){
		out << endl << rm.top().custID << endl;
		out << rm.top().vID << endl;
		out << rm.top().title;
		rm.pop();
	}
	out.close();
	
}
void rented::retrieverent(){
	vids vs;
	ifstream in("rented_vids.txt");	
	rentVids vid;
	while(!in.eof()){
		in >> vid.custID;
		in >> vid.vID;
		in.ignore();
		getline(in,vid.title);
		if(vid.title!="")
		rm.push(vid);
	}
	temp1 = rm;
}
void rented::showrented(int id){
	int c=0,x=0;
	while(!rm.empty()){
		c++;
		if(id==rm.top().custID){
			cout << rm.top().vID << "\t" << rm.top().title << endl;
		}else x++;
		rm.pop();
	}
	rm = temp1;
	if(c==x)
		throw 102;
}
void vids::returnvid(int id, int id1){
	for(it=vd.begin();it!=vd.end();it++){
		if(it->id==id){
			it->copies++;
		}
	}
}
void rented::removee(int id,int id1){
	rentVids ar[rm.size()],arr[rm.size()];
	int j=0; int s = sizeof(ar)/sizeof(*ar), ss=sizeof(arr)/sizeof(*arr);
	while(!rm.empty()){
		liv.push_back(rm.top());
		rm.pop();
	}
	for(it1=liv.begin();it1!=liv.end();it1++){
		if(it1->vID==id){
			*it1 = {};
		}
	}
	for(it1=liv.begin();it1!=liv.end();it1++){
		if(it1->vID!= 0){
			rm.push(*it1);
		}else continue;
	}
}
void custs::writecust(){
	ofstream out("customer.txt");
	while(!ci.empty()){
		out << endl << ci.front().id << endl;
		out << ci.front().name << endl;
		out << ci.front().ad;
		ci.pop();
	}
}
void custs::add(custinfo cust){
	ci.push(cust);
}
