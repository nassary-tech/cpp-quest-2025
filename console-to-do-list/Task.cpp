//
// Created by Amr Khaled on 8/31/2025.
//

#include "Task.h"
#include <string>
#include <iostream>
using namespace std;
using namespace Task_Class;

void Task::set_title(std::string title_default) {title = title_default;}

void Task::set_content(std::string content_default) {content = content_default;}

void Task::set_status(int status_default) {status = status_default;}

void Task::set_priority(int priority_default) {priority = priority_default;}

void Task::set_id(int id_default) {id = id_default;}

string Task::get_title() {return title;}

string Task::get_content() {return content;}

int Task::get_status() {return status;}

int Task::get_priority() {return priority;}

int Task::get_id() {return id;}

Task::Task(std::string title_default, std::string content_default, int status_default, int priority_default, int id_default) {}