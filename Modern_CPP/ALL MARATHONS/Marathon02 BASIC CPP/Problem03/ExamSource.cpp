#include <iostream>
#include "Exam.h"

Exam::Exam(): examType(UNIT_TEST), examCode("0"), examDuration(0) {}

Exam::Exam(etype examType, std::string examCode, int examDuration):
examType{examType}, examCode{examCode}, examDuration{examDuration} {}