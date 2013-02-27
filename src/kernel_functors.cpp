#include "log.hpp"
#include "kernel_functors.hpp"

////////////////////////////////////////////////////////////////////////////////
/** \brief Factory method for kernels. */
Kernel* Kernel::create(kernel_name name, size_t input_dim)
{
  Kernel* k_ptr;
  
  switch(name)
    {
    case K_MATERN_ISO1: k_ptr = new MaternIso1(); break;
    case K_MATERN_ISO3: k_ptr = new MaternIso3(); break;
    case K_MATERN_ISO5: k_ptr = new MaternIso5(); break;
    case K_SE_ISO: k_ptr = new SEIso(); break;
    case K_SE_ARD: k_ptr = new SEArd(); break;
    default:
      FILE_LOG(logERROR) << "Error: kernel function not supported.";
      return NULL;
    }

  k_ptr->init(input_dim);
  return k_ptr;
};

Kernel* create(std::string name, size_t imput_dim)
{
  
};

