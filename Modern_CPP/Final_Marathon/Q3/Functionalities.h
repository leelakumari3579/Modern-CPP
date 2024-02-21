#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include "ThreadHandler.h"

using ThreadPointer = std::shared_ptr<ThreadHandler>;
using ThreadContainer = std::vector<ThreadPointer>;

void AcceptData(ThreadContainer& data);

#endif // FUNCTIONALITIES_H
