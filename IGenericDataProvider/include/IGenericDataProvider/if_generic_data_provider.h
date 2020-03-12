//
// Created by jtb on 11.03.20.
//

#ifndef IGENERICDATAPROVIDER_IF_GENERIC_DATA_PROVIDER_H
#define IGENERICDATAPROVIDER_IF_GENERIC_DATA_PROVIDER_H

class IGenericDataProvider {
public:
    virtual ~IGenericDataProvider();

    virtual bool initialize() = 0;
    virtual bool start() = 0;
    virtual bool stop() = 0;
    virtual bool finalize() = 0;

};

#define DECLARE_GENERIC_DATA_PROVIDER_PLUGIN(plugin_class)                      \
    extern "C" plugin_class* load_generic_data_provider_plugin()                \
    {                                                                           \
        return new plugin_class;                                                \
    }                                                                           \
                                                                                \
    extern "C" void unload_generic_data_provider_plugin(plugin_class* object)   \
    {                                                                           \
        if(object != nullptr)                                                   \
            delete object;                                                      \
    }                                                                           \

#endif //IGENERICDATAPROVIDER_IF_GENERIC_DATA_PROVIDER_H
