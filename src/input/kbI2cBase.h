#pragma once

#include "InputBroker.h"
#include "SinglePortModule.h" // TODO: what header file to include?
#include "Wire.h"

class KbI2cBase : public Observable<const InputEvent *>, public concurrency::OSThread
{
  public:
    explicit KbI2cBase(const char *name);

  protected:
    virtual int32_t runOnce() override;

  private:
    const char *_originName;

    TwoWire *i2cBus = 0;
};
