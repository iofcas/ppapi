// Copyright (c) 2010 The Native Client Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_PROXY_PLUGIN_FILE_IO_H_
#define PPAPI_PROXY_PLUGIN_FILE_IO_H_

#include "native_client/src/include/nacl_macros.h"
#include "ppapi/c/dev/ppb_file_io_dev.h"

namespace ppapi_proxy {

// Implements the plugin (i.e., .nexe) side of the PPB_FileIO_Dev interface.
class PluginFileIO {
 public:
  static const PPB_FileIO_Dev* GetInterface();

 private:
  NACL_DISALLOW_COPY_AND_ASSIGN(PluginFileIO);
};
}  // namespace ppapi_proxy

#endif  // PPAPI_PROXY_PLUGIN_FILE_IO_H_
