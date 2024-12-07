#pragma once

#include <iostream>
#include <string>
#include <cmath>

template<typename T>
void leaveReview(const std::string& doctorName, const T& ratingType) {
    std::cout << "S-a inregistrat recenzia pentru " << doctorName << " cu rating: ";
    std::cout << "Rating: " << ratingType << std::endl;
     std::cout<<"Multumim pentru feedback!"<<std::endl;
}

template<>
void leaveReview<double>(const std::string& doctorName, const double& nota) {
    std::cout << "S-a inregistrat recenzia pentru " << doctorName<< " cu nota: "<<round(nota)<< std::endl;
    std::cout<<"Multumim pentru feedback!"<<std::endl;
}

template<>
void leaveReview<std::string>(const std::string& doctorName, const std::string& mesaj) {
    std::cout << "S-a inregistrat recenzia pentru " << doctorName <<" cu mesaj: << "<<mesaj<<" >>"<< std::endl;
    std::cout<<"Multumim pentru feedback!"<<std::endl;
}


