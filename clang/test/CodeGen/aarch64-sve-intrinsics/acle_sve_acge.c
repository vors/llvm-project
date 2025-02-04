// NOTE: Assertions have been autogenerated by utils/update_cc_test_checks.py
// REQUIRES: aarch64-registered-target
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s
// RUN: %clang_cc1 -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -Wall -emit-llvm -o - -x c++ %s | opt -S -passes=mem2reg,tailcallelim | FileCheck %s -check-prefix=CPP-CHECK
// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +sve -S -disable-O0-optnone -Werror -o /dev/null %s
#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

// CHECK-LABEL: @test_svacge_f16(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.facge.nxv8f16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv8i1(<vscale x 8 x i1> [[TMP1]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z15test_svacge_f16u10__SVBool_tu13__SVFloat16_tu13__SVFloat16_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv8i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 8 x i1> @llvm.aarch64.sve.facge.nxv8f16(<vscale x 8 x i1> [[TMP0]], <vscale x 8 x half> [[OP1:%.*]], <vscale x 8 x half> [[OP2:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv8i1(<vscale x 8 x i1> [[TMP1]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
svbool_t test_svacge_f16(svbool_t pg, svfloat16_t op1, svfloat16_t op2)
{
  return SVE_ACLE_FUNC(svacge,_f16,,)(pg, op1, op2);
}

// CHECK-LABEL: @test_svacge_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.facge.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv4i1(<vscale x 4 x i1> [[TMP1]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z15test_svacge_f32u10__SVBool_tu13__SVFloat32_tu13__SVFloat32_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.facge.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[OP2:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv4i1(<vscale x 4 x i1> [[TMP1]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
svbool_t test_svacge_f32(svbool_t pg, svfloat32_t op1, svfloat32_t op2)
{
  return SVE_ACLE_FUNC(svacge,_f32,,)(pg, op1, op2);
}

// CHECK-LABEL: @test_svacge_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.facge.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]])
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv2i1(<vscale x 2 x i1> [[TMP1]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
// CPP-CHECK-LABEL: @_Z15test_svacge_f64u10__SVBool_tu13__SVFloat64_tu13__SVFloat64_t(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.facge.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[OP2:%.*]])
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv2i1(<vscale x 2 x i1> [[TMP1]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP2]]
//
svbool_t test_svacge_f64(svbool_t pg, svfloat64_t op1, svfloat64_t op2)
{
  return SVE_ACLE_FUNC(svacge,_f64,,)(pg, op1, op2);
}

// CHECK-LABEL: @test_svacge_n_f32(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x float> poison, float [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = shufflevector <vscale x 4 x float> [[DOTSPLATINSERT]], <vscale x 4 x float> poison, <vscale x 4 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.facge.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv4i1(<vscale x 4 x i1> [[TMP2]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP3]]
//
// CPP-CHECK-LABEL: @_Z17test_svacge_n_f32u10__SVBool_tu13__SVFloat32_tf(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv4i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 4 x float> poison, float [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = shufflevector <vscale x 4 x float> [[DOTSPLATINSERT]], <vscale x 4 x float> poison, <vscale x 4 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 4 x i1> @llvm.aarch64.sve.facge.nxv4f32(<vscale x 4 x i1> [[TMP0]], <vscale x 4 x float> [[OP1:%.*]], <vscale x 4 x float> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv4i1(<vscale x 4 x i1> [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP3]]
//
svbool_t test_svacge_n_f32(svbool_t pg, svfloat32_t op1, float32_t op2)
{
  return SVE_ACLE_FUNC(svacge,_n_f32,,)(pg, op1, op2);
}

// CHECK-LABEL: @test_svacge_n_f64(
// CHECK-NEXT:  entry:
// CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 2 x double> poison, double [[OP2:%.*]], i64 0
// CHECK-NEXT:    [[TMP1:%.*]] = shufflevector <vscale x 2 x double> [[DOTSPLATINSERT]], <vscale x 2 x double> poison, <vscale x 2 x i32> zeroinitializer
// CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.facge.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[TMP1]])
// CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv2i1(<vscale x 2 x i1> [[TMP2]])
// CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP3]]
//
// CPP-CHECK-LABEL: @_Z17test_svacge_n_f64u10__SVBool_tu13__SVFloat64_td(
// CPP-CHECK-NEXT:  entry:
// CPP-CHECK-NEXT:    [[TMP0:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.convert.from.svbool.nxv2i1(<vscale x 16 x i1> [[PG:%.*]])
// CPP-CHECK-NEXT:    [[DOTSPLATINSERT:%.*]] = insertelement <vscale x 2 x double> poison, double [[OP2:%.*]], i64 0
// CPP-CHECK-NEXT:    [[TMP1:%.*]] = shufflevector <vscale x 2 x double> [[DOTSPLATINSERT]], <vscale x 2 x double> poison, <vscale x 2 x i32> zeroinitializer
// CPP-CHECK-NEXT:    [[TMP2:%.*]] = tail call <vscale x 2 x i1> @llvm.aarch64.sve.facge.nxv2f64(<vscale x 2 x i1> [[TMP0]], <vscale x 2 x double> [[OP1:%.*]], <vscale x 2 x double> [[TMP1]])
// CPP-CHECK-NEXT:    [[TMP3:%.*]] = tail call <vscale x 16 x i1> @llvm.aarch64.sve.convert.to.svbool.nxv2i1(<vscale x 2 x i1> [[TMP2]])
// CPP-CHECK-NEXT:    ret <vscale x 16 x i1> [[TMP3]]
//
svbool_t test_svacge_n_f64(svbool_t pg, svfloat64_t op1, float64_t op2)
{
  return SVE_ACLE_FUNC(svacge,_n_f64,,)(pg, op1, op2);
}
