// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef PPAPI_CPP_SCRIPTABLE_OBJECT_H_
#define PPAPI_CPP_SCRIPTABLE_OBJECT_H_

#include <vector>

typedef struct _ppp_Class PPP_Class;

namespace pp {

class Var;

class ScriptableObject {
 public:
  ScriptableObject() {}
  virtual ~ScriptableObject() {}

  // The default implementation returns false.
  virtual bool HasProperty(const Var& name, Var* exception);

  // The default implementation returns false.
  virtual bool HasMethod(const Var& name, Var* exception);

  // The default implementation sets an exception that the property doesn't
  // exist.
  virtual Var GetProperty(const Var& name, Var* exception);

  // The default implementation returns no properties.
  virtual void GetAllPropertyNames(std::vector<Var>* properties,
                                   Var* exception);

  // The default implementation sets an exception that the property can not be
  // set.
  virtual void SetProperty(const Var& name,
                           const Var& value,
                           Var* exception);

  // The default implementation sets an exception that the method does not
  // exist.
  virtual void RemoveProperty(const Var& name,
                              Var* exception);

  // TODO(brettw) need native array access here.

  // method_name is guaranteed to be either a string or an integer.
  //
  // The default implementation sets an exception that the method does not
  // exist.
  virtual Var Call(const Var& method_name,
                   const std::vector<Var>& args,
                   Var* exception);

  // The default implementation sets an exception that the method does not
  // exist.
  virtual Var Construct(const std::vector<Var>& args,
                        Var* exception);

 private:
  friend class Var;
  static const PPP_Class* GetClass();

  // Unimplemented, copy and assigmnent is not allowed.
  ScriptableObject(const ScriptableObject& other);
  ScriptableObject& operator=(const ScriptableObject& other);
};

}  // namespace pp

#endif  // PPAPI_CPP_SCRIPTABLE_OBJECT_H_