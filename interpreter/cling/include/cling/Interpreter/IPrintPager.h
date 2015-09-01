//
// Created by boris on 25/08/15.
//

#ifndef CLING_IPRINTPAGER_H
#define CLING_IPRINTPAGER_H

#include <string>

namespace llvm {
  class raw_ostream;
}

namespace cling {
  class IPrintPager {

  public:
    virtual void printPaged(llvm::raw_ostream &Out, std::string text) = 0;
  };
}
#endif //CLING_IPRINTPAGER_H
