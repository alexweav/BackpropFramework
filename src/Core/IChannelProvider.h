#ifndef SRC_CORE_ICHANNELPROVIDER_H_
#define SRC_CORE_ICHANNELPROVIDER_H_

#include <memory>

class Channel;

class IChannelProvider {
 public:
     virtual Channel GetChannel(void) const = 0;
};

using IChannelProviderPtr = std::shared_ptr<IChannelProvider>;

#endif  // SRC_CORE_ICHANNELPROVIDER_H_
