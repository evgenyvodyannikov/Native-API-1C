#ifndef SAMPLEADDIN_H
#define SAMPLEADDIN_H

#include "Component.h"

class SampleAddIn final : public Component {
public:
    const char *Version = u8"1.0.0";

    SampleAddIn();

private:
    std::string extensionName() override;

    variant_t add(const variant_t &a, const variant_t &b);

    void message(const variant_t &msg);

    void sleep(const variant_t &delay);

    void assign(variant_t &out);

    variant_t samplePropertyValue();

    variant_t currentDate();

    std::shared_ptr<variant_t> sample_property;

    variant_t startTimer();
};

#endif //SAMPLEADDIN_H
