#pragma once

#include "PropertyAbs.hpp"
#include <unordered_map>

namespace tinyxml2
{
    class XMLElement;
}

namespace rahina
{

class PropertyOwner
{
public:
    virtual ~PropertyOwner() {}
    void registerProperty(PropertyAbs &propertyP, const std::string &nameP);

    PropertyAbs *findProperty(const std::string &nameP);
    const PropertyAbs *findProperty(const std::string &nameP) const;

    bool read(const tinyxml2::XMLElement *xmlElementP);

private:
    std::unordered_map<std::string, PropertyAbs *> propertiesM;
};

#define DECL_STRING_PROP(p_name) \
    private: PropertyString p_name##M; \
    public: const std::string &get##p_name() const { return p_name##M.getValue(); } \
    void set##p_name(const std::string &valueP) { p_name##M.setValue(valueP); } \
    PropertyString &get##Property##p_name() { return p_name##M; } \
    private:

#define DECL_FLOAT_PROP(p_name) \
    private: PropertyFloat p_name##M; \
    public: float get##p_name() const { return p_name##M.getValue(); } \
    void set##p_name(const float valueP) { p_name##M.setValue(valueP); } \
    PropertyFloat &get##Property##p_name() { return p_name##M; } \
    private:

#define INIT_PROP(p_name) p_name##M{*this, #p_name}

} // rahina

