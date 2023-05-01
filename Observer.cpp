#include "stdafx.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

// �[��̼Ҧ� ��D�D����N�䪬�A���ܮɳq���j�a

//�D�D����
class ISubject {
public:
	virtual ~ISubject(){};
	virtual void Attach( IObserver *observer ) = 0;
	virtual void Detach( IObserver *observer ) = 0;
	virtual void Notify() = 0;
};

//�D�D��@
class Subject : public ISubject {
public:
	virtual ~Subject() {
		cout << "Subject destructor\n";
	}
	void Attach( IObserver *observer ) override {
		list_observer_.push_back( observer );
	}
	void Detach( IObserver *observer ) override {
		list_observer_.remove( observer );
	}
	void Notify() override {
		list<IObserver *>::iterator iterator = list_observer_.begin();
		HowManyObserver();
		while ( iterator != list_observer_.end() ) {
			( *iterator )->Update( message_ );
			++iterator;
		}
	}
	void CreateMessage( string message = "Empty" ) {
		this->message_ = message;
		Notify();
	}
	void HowManyObserver() {
		cout << "There are " << list_observer_.size() << " observers in the list.\n";
	}
	void SomeBusinessLogic() {
		this->message_ = "change message message";
		Notify();
		cout << "I'm about to do some thing important\n";
	}
private:
	list<IObserver *> list_observer_;
	string message_;
};

// �[��̤���
class IObserver {
public:
	virtual ~IObserver(){};
	virtual void Update(const string &message_from_subject) = 0;
};

// �ݩ� string message_from_subject_;�ASubject &subject_;�Astatic int static_number_;�Aint number_;
// ��k constructor destructor Update RemoveMeFromTheList PrintInf
class Observer : public IObserver {
public:
	Observer( Subject &subject ) : subject_( subject ) {
		this->subject_.Attach(this);
		cout << "Observer constructor\"" << ++Observer::static_number_ << "\".\n";
		this->number_ = Observer::static_number_;
	}
	virtual ~Observer() {
		cout << "Observer destructor\"" << this->number_ << "\".\n";
	}
	void Update( const string &message_from_subject ) override {
		message_from_subject_ = message_from_subject;
		PrintInfo();
	}
	void RemoveMeFromTheList() {
		subject_.Detach( this );
		cout << "Observer \"" << number_ << "\" removed from the list.\n";
	}
	void PrintInfo() {
		cout << "Observer \"" << this->number_ << "\": a new message is available --> " << this->message_from_subject_ << "\n";
	}
private:
	string message_from_subject_;
	Subject &subject_;
	static int static_number_;
	int number_;
};

int Observer::static_number_ = 0;

void ClientCode() {
	Subject *subject = new Subject;
	Observer *observer1 = new Observer(*subject);
	Observer *observer2 = new Observer(*subject);
	Observer *observer3 = new Observer(*subject);

	subject->CreateMessage( "Hello World" );
	observer3->RemoveMeFromTheList();
	observer2->RemoveMeFromTheList();
	observer1->RemoveMeFromTheList();

	delete observer3;
	delete observer2;
	delete observer1;
	delete subject;
	observer3 = NULL;
	observer2 = NULL;
	observer1 = NULL;
	subject = NULL;
}

int main() {
	ClientCode();
	string mystr; //�Ψ��קK��ƳQRETURN�X�h�A��cin�d��
	getline( cin, mystr );
	return 0;
}