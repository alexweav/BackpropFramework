#ifndef SRC_OPERATIONS_BASE_ICHANNELPROVIDER_H_
#define SRC_OPERATIONS_BASE_ICHANNELPROVIDER_H_

class Channel;

class IChannelProvider {
 public:
     virtual Channel GetChannel(void) const = 0;
};

using IChannelProviderPtr = std::shared_ptr<IChannelProvider>;

#endif  // SRC_OPERATIONS_BASE_ICHANNELPROVIDER_H_
