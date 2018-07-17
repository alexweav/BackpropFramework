#ifndef SRC_CORE_NODEFACADE_H_
#define SRC_CORE_NODEFACADE_H_

#include <initializer_list>
#include <memory>

#include "Core/IChannelProvider.h"
#include "Core/Node.h"

class NodeFacade {
 public:
    NodeFacade(std::initializer_list<IChannelProviderPtr>);
    NodePtr GetNode(void) const;

 protected:
    void AttachExecutor(const std::shared_ptr<IExecutor> executor);
    void AttachDifferentiableExecutor(const std::shared_ptr<IDifferentiableExecutor> executor);

 private:
    NodePtr _node;
};

#endif  // SRC_CORE_NODEFACADE_H_
