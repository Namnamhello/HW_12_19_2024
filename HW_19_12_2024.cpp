#include <iostream>
#include <string>

using namespace std;

struct BookNode{
	string name;
	int papes;
	BookNode* first;
	BookNode* second;
	
	BookNode(string n, int p) : name(n), papes(p), first(nullptr), second(nullptr){}
};

// Ham dem so chuong
int Dem_Chuong(BookNode* book){
	if(book== nullptr) return 0;
	
	int count = 0;
	BookNode* hien_tai= book->second;
	while(hien_tai!= nullptr){
		count++;
		hien_tai= hien_tai->second;
	}
	return count;
}

void Max_Chuong(BookNode* book){
	if (book == nullptr) {
        cout << "Cuon sach khong co chuong nao." << endl;
        return;
    }
	BookNode* hien_tai= book->second;
	
	int max_page=hien_tai->papes;
	string max=hien_tai->name;
	while(hien_tai!=nullptr){
		if(hien_tai->papes>max_page){
			max_page=hien_tai->papes;
			max=hien_tai->name;
		}
		hien_tai=hien_tai->second;
	}
	cout<<max<<" co so trang nhieu nhat voi "<<max_page<<" trang.";
}



// Dem so trang cua cuon sach
int Tong_trang(BookNode* book){
	if(book==nullptr) return 0;
	int count=0;
	BookNode* hien_tai= book->second;
	while(hien_tai!=nullptr){
		count+=hien_tai->papes;
		hien_tai=hien_tai->second;
	}
	return count;
}

// Ham tim va xoa 
bool deleteNode(BookNode* book, string name){
	if (book==nullptr) return false;
	
	BookNode* hien_tai= book->second;
	BookNode* truoc= nullptr;
	
	 while (hien_tai != nullptr) {
        if (hien_tai->name == name) {
            if (truoc == nullptr) {
                book->second = hien_tai->second;
            } else {
                truoc->second = hien_tai->second;
            }
            delete hien_tai;
            return true;
        }
        truoc = hien_tai;
        hien_tai = hien_tai->second;
    }
    return false;
}

int main(){
	BookNode* book= new BookNode("Book", 0);
	BookNode* chuong1= new BookNode("Chuong1", 50);
	BookNode* chuong2= new BookNode("Chuong2", 40);
	BookNode* chuong3= new BookNode("Chuong3", 30);
	
	book->second=chuong1;
	chuong1->second=chuong2;
	chuong2->second=chuong3;
	
	cout<<"Tong so chuong cua cuon sach la: "<<Dem_Chuong(book)<<endl;
	Max_Chuong(book);
	
	string t;
	cout<<"\nMoi nhap chuong can xoa: ";
	cin>>t;
	if(deleteNode(book,t)){
		cout<<t<<" da duoc xoa"<<endl;
		cout<<"So chuong sau khi xoa: "<< Dem_Chuong(book)<<endl;
		cout<<"Tong so trang cua sach: "<< Tong_trang(book);
	}
	else {
        cout << "Khong tim thay chuong " << t << endl;
    }
	while (book->second != nullptr) {
        deleteNode(book, book->second->name);
    }
    delete book;
	return 0;
}