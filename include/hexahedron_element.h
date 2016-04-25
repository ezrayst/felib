#ifndef FELIB_HEXAHEDRON_ELEMENT_H_
#define FELIB_HEXAHEDRON_ELEMENT_H_

#include <algorithm>
#include <array>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>

#include "hexahedron_quadrature.h"
#include "hexahedron_shapefn.h"
#include "node_base.h"
#include "quadrature_base.h"
#include "shapefn_base.h"

//! \brief Hexhedron element derived class
//! \tparam Tdim Dimension
//! \tparam Tnnodes Number of nodes
//! \tparam Tnquadratures Number of quadrature points
namespace felib {
template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class HexahedronElement;
}

template <unsigned Tdim, unsigned Tnnodes, unsigned Tnquadratures>
class felib::HexahedronElement
    : public felib::ElementBase<Tdim, Tnnodes, Tnquadratures> {

 public:
  // Default constructor with element id
  //! \param[in] id element id
  HexahedronElement(const unsigned& id)
      : felib::ElementBase<Tdim, Tnnodes, Tnquadratures>(id) {
    shapefn_ptr_ = std::unique_ptr<felib::HexahedronShapeFn<Tdim, Tnnodes>>(
        new felib::HexahedronShapeFn<Tdim, Tnnodes>());
    quadrature_ptr_ =
        std::unique_ptr<felib::HexahedronQuadrature<Tdim, Tnquadratures>>(
            new felib::HexahedronQuadrature<Tdim, Tnquadratures>());
  }

  //! Add node pointers to hexahedron element
  //! \param[in] node_ptr Pointer to a node in the element
  bool add_node_ptr(std::shared_ptr<NodeBase<Tdim>>& node_ptr) { return 1; }

  //! Add edge node pointers to hexahedron element
  //! \param[in] edge_node_ptr Pointer to an edge_node in the element
  bool add_edge_node_ptr(std::shared_ptr<NodeBase<Tdim>>& edge_node_ptr) {
    return 1;
  }

  //! Return the length of the hexahedron element
  //! \param[out] volume_ length of the element
  double volume() { return 1.; }

 protected:
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::shapefn_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::quadrature_ptr_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::volume_;
  using felib::ElementBase<Tdim, Tnnodes, Tnquadratures>::vec_nodes_ptr_;
};

// #include "hexahedron_element.tcc"
#endif  // FELIB_HEXAHEDRON_ELEMENT_H_
