//
// Created by Amr Khaled on 8/31/2025.
//

#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
using namespace std;

namespace Task_Class
{
    class Task
    {
    private:
        std::string title;
        std::string content;
        int status{};
        int priority{};
        int id{};

    public:
        Task(string title_default = "UnTitled", string content_default = "No Content", int status_default = 0, int priority_default = 2, int id_default = 0);

        void set_title(std::string title_in);
        void set_content(std::string content_in);
        void set_status(int status_in);
        void set_priority(int priority_in);
        void set_id(int ID);

        std::string get_title();
        std::string get_content();
        int get_status();
        int get_priority();
        int get_id();
    };
}

#endif //TASK_H