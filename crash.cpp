#include "mlir/Dialect/LLVMIR/LLVMTypes.h"

namespace mlir::foo {

static Type bar(MLIRContext* context) {
    return LLVM::LLVMVoidType::get(context);
}

}  // namespace mlir::foo
