#ifndef SRC_CORE_NODEFACADE_H_
#define SRC_CORE_NODEFACADE_H_

#include <initializer_list>
#include <memory>
#include <vector>

#include "Core/IChannelProvider.h"
#include "Core/Node.h"

class NodeFacade: public IChannelProvider {
 public:
    template <class ...Args> explicit NodeFacade(const Args&... args);
    NodeFacade(std::initializer_list<IChannelProviderPtr>);
    NodePtr GetNode(void) const;
    int Arity(void);
    std::vector<Channel> Channels(void) const;
    Channel Channels(int index) const;
    int NumChannels(void);
    Channel GetChannel(void) const;

 protected:
    void AttachExecutor(const std::shared_ptr<IExecutor> executor);
    void AttachDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor);

 private:
    NodePtr _node;
};

#endif  // SRC_CORE_NODEFACADE_H_
