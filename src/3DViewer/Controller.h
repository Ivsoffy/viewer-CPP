#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"

class Controller
    {
        private:
            Model model_;
        public:
            void set_x(const char* x_value);
            void set_line(const char* str);
            double get_result();
            int get_error();
    };


#endif // CONTROLLER_H
