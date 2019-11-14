#pragma once

#include "Application.h"

//-----------------------------------------------------------------------------
// Win32Application
//-----------------------------------------------------------------------------
class Win32Application : public Application
{
public:
    Win32Application();

    virtual void OutputMessage(const std::string& message) const override;
    virtual bool ProcessMessages() override;
};