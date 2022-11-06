//------------------------------------------------------------------
// punkt3d.cpp
// Copyright 04.11.2022
// Author: KJR
//------------------------------------------------------------------
#include "punkt3d.h"

// Definition der statischen Variablen in einer cpp-Datei
// Ab C++ 17 nicht mehr notwendig
const size_t Punkt3D::DIM = 3;

Punkt3D::~Punkt3D()
{
  delete [] koord;
  koord = nullptr;
}

/*
std::ostream& operator<<(std::ostream& os, const Punkt3D& p) {
  p.output(os);
  return os;
}
*/
