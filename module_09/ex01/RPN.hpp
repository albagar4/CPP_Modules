#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
#include <stdlib.h>
#include <stdint.h>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <stack>

bool correctChar(char c);
float evaluatePhase(int first, int second, char c);
int evaluateRPN(char *argv);

#endif