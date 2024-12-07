#pragma once

#include "consultation.h"
#include <memory>

template<typename AgeCategory>
class ConsultationCreator
{
public:
    virtual ~ConsultationCreator() = default;
    virtual std::unique_ptr<Consultation<AgeCategory>> createConsultation() = 0;
};

class ChildConsultationCreator : public ConsultationCreator<Child>
{
public:
    std::unique_ptr<Consultation<Child>> createConsultation() override
    {
        return std::make_unique<Consultation<Child>>();
    }
};

class AdultConsultationCreator : public ConsultationCreator<Adult>
{
public:
    std::unique_ptr<Consultation<Adult>> createConsultation() override
    {
        return std::make_unique<Consultation<Adult>>();
    }
};

class SeniorConsultationCreator : public ConsultationCreator<Senior>
{
public:
    std::unique_ptr<Consultation<Senior>> createConsultation() override
    {
        return std::make_unique<Consultation<Senior>>();
    }
};

