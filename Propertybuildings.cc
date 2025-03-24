#include "Propertybuildings.h"
#include <cstddef> 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

Propertybuildings::Propertybuildings(int rent, Player* owner, const string& Faculty, const string& name, int pos): rent{rent}, owner{owner}, Faculty{Faculty}, Buildings(name, pos) {}
