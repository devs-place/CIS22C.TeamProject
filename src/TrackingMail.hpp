// Specification file for the Date class
// Written By: Keshav Gurushankar
// IDE: Visual Studio Code

#ifndef TRACKING_MAIL_H
#define TRACKING_MAIL_H

#include <iostream>
#include "Mail.hpp"

using std::ostream;
using std::string;

class TrackingMail
{
private:
	Mail m;

public:
	TrackingMail(Mail mail){this->m = mail;};

	Mail getMail() { return m; }

	// Other functions
	friend ostream &operator<<(ostream &, Mail &);
	//Comparing tracking number
	bool operator<(TrackingMail &o) { return (this->m.getTrackingNumber() < o.m.getTrackingNumber()); }
	bool operator>(TrackingMail &o) { return (this->m.getTrackingNumber() > o.m.getTrackingNumber()); }
	bool operator==(TrackingMail &o) { return (this->m.getTrackingNumber() == o.m.getTrackingNumber()); }
	bool operator!=(TrackingMail &o) { return (this->m.getTrackingNumber() != o.m.getTrackingNumber()); }
};
ostream &operator<<(ostream &out, TrackingMail &m)
{
	out << m;
	return out;
}

#endif
