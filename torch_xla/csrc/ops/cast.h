#pragma once

#include <c10/core/ScalarType.h>

#include "torch_xla/csrc/ir.h"

namespace torch_xla {
namespace ir {
namespace ops {

class Cast : public Node {
 public:
  Cast(const Value& input, xla::PrimitiveType type);
  Cast(const Value& input, at::ScalarType dtype);

  std::string ToString() const override;

  NodePtr Clone(OpList operands) const override;

  XlaOpVector Lower(LoweringContext* loctx) const override;

  xla::PrimitiveType type() const { return type_; }

 private:
  xla::PrimitiveType type_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_xla