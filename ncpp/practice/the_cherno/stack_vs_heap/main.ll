; ModuleID = 'src/main.cpp'
source_filename = "src/main.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

%"class.std::ios_base::Init" = type { i8 }
%struct.demo_obj = type { float, float, float }

$_ZN8demo_objC2Ev = comdat any

@_ZStL8__ioinit = internal global %"class.std::ios_base::Init" zeroinitializer, align 1
@__dso_handle = external hidden global i8
@llvm.global_ctors = appending global [1 x { i32, void ()*, i8* }] [{ i32, void ()*, i8* } { i32 65535, void ()* @_GLOBAL__sub_I_main.cpp, i8* null }]

; Function Attrs: noinline sspstrong uwtable
define internal void @__cxx_global_var_init() #0 section ".text.startup" {
  call void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"* @_ZStL8__ioinit)
  %1 = call i32 @__cxa_atexit(void (i8*)* bitcast (void (%"class.std::ios_base::Init"*)* @_ZNSt8ios_base4InitD1Ev to void (i8*)*), i8* getelementptr inbounds (%"class.std::ios_base::Init", %"class.std::ios_base::Init"* @_ZStL8__ioinit, i32 0, i32 0), i8* @__dso_handle) #3
  ret void
}

declare void @_ZNSt8ios_base4InitC1Ev(%"class.std::ios_base::Init"*) unnamed_addr #1

; Function Attrs: nounwind
declare void @_ZNSt8ios_base4InitD1Ev(%"class.std::ios_base::Init"*) unnamed_addr #2

; Function Attrs: nounwind
declare i32 @__cxa_atexit(void (i8*)*, i8*, i8*) #3

; Function Attrs: noinline norecurse optnone sspstrong uwtable
define dso_local i32 @main(i32 %0, i8** %1) #4 personality i8* bitcast (i32 (...)* @__gxx_personality_v0 to i8*) {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i8**, align 8
  %6 = alloca i32, align 4
  %7 = alloca [5 x i32], align 16
  %8 = alloca %struct.demo_obj, align 4
  %9 = alloca i32*, align 8
  %10 = alloca i32*, align 8
  %11 = alloca %struct.demo_obj*, align 8
  %12 = alloca i8*, align 8
  %13 = alloca i32, align 4
  store i32 0, i32* %3, align 4
  store i32 %0, i32* %4, align 4
  store i8** %1, i8*** %5, align 8
  store i32 5, i32* %6, align 4
  %14 = getelementptr inbounds [5 x i32], [5 x i32]* %7, i64 0, i64 0
  store i32 5, i32* %14, align 16
  %15 = getelementptr inbounds [5 x i32], [5 x i32]* %7, i64 0, i64 1
  store i32 4, i32* %15, align 4
  %16 = getelementptr inbounds [5 x i32], [5 x i32]* %7, i64 0, i64 2
  store i32 3, i32* %16, align 8
  %17 = getelementptr inbounds [5 x i32], [5 x i32]* %7, i64 0, i64 3
  store i32 2, i32* %17, align 4
  %18 = getelementptr inbounds [5 x i32], [5 x i32]* %7, i64 0, i64 4
  store i32 1, i32* %18, align 16
  call void @_ZN8demo_objC2Ev(%struct.demo_obj* %8)
  %19 = call noalias nonnull i8* @_Znwm(i64 4) #8
  %20 = bitcast i8* %19 to i32*
  store i32* %20, i32** %9, align 8
  %21 = load i32*, i32** %9, align 8
  store i32 5, i32* %21, align 4
  %22 = call noalias nonnull i8* @_Znam(i64 20) #8
  %23 = bitcast i8* %22 to i32*
  store i32* %23, i32** %10, align 8
  %24 = load i32*, i32** %10, align 8
  %25 = getelementptr inbounds i32, i32* %24, i64 0
  store i32 5, i32* %25, align 4
  %26 = load i32*, i32** %10, align 8
  %27 = getelementptr inbounds i32, i32* %26, i64 1
  store i32 4, i32* %27, align 4
  %28 = load i32*, i32** %10, align 8
  %29 = getelementptr inbounds i32, i32* %28, i64 2
  store i32 3, i32* %29, align 4
  %30 = load i32*, i32** %10, align 8
  %31 = getelementptr inbounds i32, i32* %30, i64 3
  store i32 2, i32* %31, align 4
  %32 = load i32*, i32** %10, align 8
  %33 = getelementptr inbounds i32, i32* %32, i64 4
  store i32 1, i32* %33, align 4
  %34 = call noalias nonnull i8* @_Znwm(i64 12) #8
  %35 = bitcast i8* %34 to %struct.demo_obj*
  invoke void @_ZN8demo_objC2Ev(%struct.demo_obj* %35)
          to label %36 unwind label %52

36:                                               ; preds = %2
  store %struct.demo_obj* %35, %struct.demo_obj** %11, align 8
  %37 = load i32*, i32** %9, align 8
  %38 = icmp eq i32* %37, null
  br i1 %38, label %41, label %39

39:                                               ; preds = %36
  %40 = bitcast i32* %37 to i8*
  call void @_ZdlPv(i8* %40) #9
  br label %41

41:                                               ; preds = %39, %36
  %42 = load i32*, i32** %10, align 8
  %43 = icmp eq i32* %42, null
  br i1 %43, label %46, label %44

44:                                               ; preds = %41
  %45 = bitcast i32* %42 to i8*
  call void @_ZdaPv(i8* %45) #9
  br label %46

46:                                               ; preds = %44, %41
  %47 = load %struct.demo_obj*, %struct.demo_obj** %11, align 8
  %48 = icmp eq %struct.demo_obj* %47, null
  br i1 %48, label %51, label %49

49:                                               ; preds = %46
  %50 = bitcast %struct.demo_obj* %47 to i8*
  call void @_ZdlPv(i8* %50) #9
  br label %51

51:                                               ; preds = %49, %46
  ret i32 0

52:                                               ; preds = %2
  %53 = landingpad { i8*, i32 }
          cleanup
  %54 = extractvalue { i8*, i32 } %53, 0
  store i8* %54, i8** %12, align 8
  %55 = extractvalue { i8*, i32 } %53, 1
  store i32 %55, i32* %13, align 4
  call void @_ZdlPv(i8* %34) #9
  br label %56

56:                                               ; preds = %52
  %57 = load i8*, i8** %12, align 8
  %58 = load i32, i32* %13, align 4
  %59 = insertvalue { i8*, i32 } undef, i8* %57, 0
  %60 = insertvalue { i8*, i32 } %59, i32 %58, 1
  resume { i8*, i32 } %60
}

; Function Attrs: noinline nounwind optnone sspstrong uwtable
define linkonce_odr dso_local void @_ZN8demo_objC2Ev(%struct.demo_obj* %0) unnamed_addr #5 comdat align 2 {
  %2 = alloca %struct.demo_obj*, align 8
  store %struct.demo_obj* %0, %struct.demo_obj** %2, align 8
  %3 = load %struct.demo_obj*, %struct.demo_obj** %2, align 8
  %4 = getelementptr inbounds %struct.demo_obj, %struct.demo_obj* %3, i32 0, i32 0
  store float 1.000000e+01, float* %4, align 4
  %5 = getelementptr inbounds %struct.demo_obj, %struct.demo_obj* %3, i32 0, i32 1
  store float 2.000000e+01, float* %5, align 4
  %6 = getelementptr inbounds %struct.demo_obj, %struct.demo_obj* %3, i32 0, i32 2
  store float 3.000000e+01, float* %6, align 4
  ret void
}

; Function Attrs: nobuiltin allocsize(0)
declare nonnull i8* @_Znwm(i64) #6

; Function Attrs: nobuiltin allocsize(0)
declare nonnull i8* @_Znam(i64) #6

declare i32 @__gxx_personality_v0(...)

; Function Attrs: nobuiltin nounwind
declare void @_ZdlPv(i8*) #7

; Function Attrs: nobuiltin nounwind
declare void @_ZdaPv(i8*) #7

; Function Attrs: noinline sspstrong uwtable
define internal void @_GLOBAL__sub_I_main.cpp() #0 section ".text.startup" {
  call void @__cxx_global_var_init()
  ret void
}

attributes #0 = { noinline sspstrong uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
attributes #4 = { noinline norecurse optnone sspstrong uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noinline nounwind optnone sspstrong uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #6 = { nobuiltin allocsize(0) "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #7 = { nobuiltin nounwind "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #8 = { builtin allocsize(0) }
attributes #9 = { builtin nounwind }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{!"clang version 11.0.1"}
