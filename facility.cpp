#include "facility.h"
#include <iostream>

using namespace std;

Facillity::Facility();

Facility::Facility(char c);

Facility::Facility(const Facility& f);

Facility::~Facility();

Facility& Facility::operator= (const Facility& f);

