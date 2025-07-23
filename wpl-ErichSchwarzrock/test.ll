; ModuleID = '123'
source_filename = "123"

@globalVar = dso_local global i32 5
@0 = private unnamed_addr constant [13 x i8] c"\22Error func\22\00", align 1
@1 = private unnamed_addr constant [15 x i8] c"\22string exmpl\22\00", align 1
@2 = private unnamed_addr constant [13 x i8] c"\22Error func\22\00", align 1
@3 = private unnamed_addr constant [10 x i8] c"\22Error 1\22\00", align 1
@4 = private unnamed_addr constant [10 x i8] c"\22Error 2\22\00", align 1
@5 = private unnamed_addr constant [10 x i8] c"\22Error 3\22\00", align 1
@6 = private unnamed_addr constant [10 x i8] c"\22Error 4\22\00", align 1
@7 = private unnamed_addr constant [12 x i8] c"\22Error 4.3\22\00", align 1
@8 = private unnamed_addr constant [12 x i8] c"\22Error 4.6\22\00", align 1
@9 = private unnamed_addr constant [10 x i8] c"\22Error 5\22\00", align 1
@10 = private unnamed_addr constant [11 x i8] c"\22Error 5 \22\00", align 1
@11 = private unnamed_addr constant [10 x i8] c"\22Error 6\22\00", align 1
@12 = private unnamed_addr constant [10 x i8] c"\22Error 7\22\00", align 1
@13 = private unnamed_addr constant [10 x i8] c"\22Error 8\22\00", align 1
@14 = private unnamed_addr constant [10 x i8] c"\22Error 9\22\00", align 1
@15 = private unnamed_addr constant [5 x i8] c"\22we\22\00", align 1
@16 = private unnamed_addr constant [11 x i8] c"\22Error 10\22\00", align 1
@17 = private unnamed_addr constant [11 x i8] c"\22Error 11\22\00", align 1
@18 = private unnamed_addr constant [12 x i8] c"\22Error 12a\22\00", align 1
@19 = private unnamed_addr constant [12 x i8] c"\22Error 12b\22\00", align 1
@20 = private unnamed_addr constant [13 x i8] c"\22Error ~= F\22\00", align 1
@21 = private unnamed_addr constant [13 x i8] c"\22Error ~= T\22\00", align 1
@22 = private unnamed_addr constant [12 x i8] c"\22Error ~ F\22\00", align 1
@23 = private unnamed_addr constant [12 x i8] c"\22Error ~ T\22\00", align 1
@24 = private unnamed_addr constant [12 x i8] c"\22Error = F\22\00", align 1
@25 = private unnamed_addr constant [12 x i8] c"\22Error = T\22\00", align 1
@26 = private unnamed_addr constant [12 x i8] c"\22Error > F\22\00", align 1
@27 = private unnamed_addr constant [12 x i8] c"\22Error > T\22\00", align 1
@28 = private unnamed_addr constant [12 x i8] c"\22Error < F\22\00", align 1
@29 = private unnamed_addr constant [12 x i8] c"\22Error < T\22\00", align 1
@30 = private unnamed_addr constant [13 x i8] c"\22Error >= F\22\00", align 1
@31 = private unnamed_addr constant [13 x i8] c"\22Error >= T\22\00", align 1
@32 = private unnamed_addr constant [13 x i8] c"\22Error <= F\22\00", align 1
@33 = private unnamed_addr constant [13 x i8] c"\22Error <= T\22\00", align 1
@34 = private unnamed_addr constant [13 x i8] c"\22Error & TT\22\00", align 1
@35 = private unnamed_addr constant [13 x i8] c"\22Error & TF\22\00", align 1
@36 = private unnamed_addr constant [13 x i8] c"\22Error & FT\22\00", align 1
@37 = private unnamed_addr constant [13 x i8] c"\22Error & FF\22\00", align 1
@38 = private unnamed_addr constant [13 x i8] c"\22Error | TT\22\00", align 1
@39 = private unnamed_addr constant [13 x i8] c"\22Error | TF\22\00", align 1
@40 = private unnamed_addr constant [13 x i8] c"\22Error | FT\22\00", align 1
@41 = private unnamed_addr constant [13 x i8] c"\22Error | FF\22\00", align 1
@42 = private unnamed_addr constant [14 x i8] c"\22Error |& FF\22\00", align 1
@43 = private unnamed_addr constant [14 x i8] c"\22Error &| FF\22\00", align 1
@44 = private unnamed_addr constant [14 x i8] c"\22Error () FF\22\00", align 1
@45 = private unnamed_addr constant [11 x i8] c"\22Error +*\22\00", align 1
@46 = private unnamed_addr constant [13 x i8] c"\22Error ()+*\22\00", align 1
@47 = private unnamed_addr constant [11 x i8] c"\22Error *+\22\00", align 1
@48 = private unnamed_addr constant [13 x i8] c"\22Error ()*+\22\00", align 1
@49 = private unnamed_addr constant [12 x i8] c"\22Error eql\22\00", align 1
@50 = private unnamed_addr constant [16 x i8] c"\22Error not eql\22\00", align 1
@51 = private unnamed_addr constant [6 x i8] c"\22Ran\22\00", align 1

declare void @print(i8*)

define i32 @intf() {
entry:
  ret i32 3
}

define i32 @boolf(i32 %0, i32 %1, i8* %2) {
entry:
  %x = alloca i32, align 4
  store i32 %0, i32* %x, align 4
  %f = alloca i32, align 4
  store i32 %1, i32* %f, align 4
  %w = alloca i8*, align 8
  store i8* %2, i8** %w, align 8
  %x1 = load i32, i32* %x, align 4
  %3 = icmp eq i32 %x1, 32
  %4 = zext i1 %3 to i32
  %f2 = load i32, i32* %f, align 4
  %5 = trunc i32 %4 to i1
  %6 = trunc i32 %f2 to i1
  %7 = and i1 %5, %6
  %8 = zext i1 %7 to i32
  %9 = trunc i32 %8 to i1
  %10 = xor i1 %9, true
  %11 = zext i1 %10 to i32
  %12 = trunc i32 %11 to i1
  br i1 %12, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @0, i32 0, i32 0))
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  ret i32 1
}

define i8* @strf() {
entry:
  ret i8* getelementptr inbounds ([15 x i8], [15 x i8]* @1, i32 0, i32 0)
}

define void @testProc(i32 %0, i32 %1, i8* %2) {
entry:
  %x = alloca i32, align 4
  store i32 %0, i32* %x, align 4
  %f = alloca i32, align 4
  store i32 %1, i32* %f, align 4
  %w = alloca i8*, align 8
  store i8* %2, i8** %w, align 8
  %x1 = load i32, i32* %x, align 4
  %3 = icmp eq i32 %x1, 32
  %4 = zext i1 %3 to i32
  %f2 = load i32, i32* %f, align 4
  %5 = trunc i32 %4 to i1
  %6 = trunc i32 %f2 to i1
  %7 = and i1 %5, %6
  %8 = zext i1 %7 to i32
  %9 = trunc i32 %8 to i1
  %10 = xor i1 %9, true
  %11 = zext i1 %10 to i32
  %12 = trunc i32 %11 to i1
  br i1 %12, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @2, i32 0, i32 0))
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  store i32 3, i32* @globalVar, align 4
  ret void
}

define void @testProc2() {
entry:
  store i32 320, i32* @globalVar, align 4
  ret void
}

define i32 @program() {
entry:
  %anInt = alloca i32, align 4
  store i32 32, i32* %anInt, align 4
  %aString = alloca i8*, align 8
  %aBoolean = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  store i32 1, i32* %b, align 4
  %b1 = load i32, i32* %b, align 4
  store i32 %b1, i32* %a, align 4
  %a2 = load i32, i32* %a, align 4
  %b3 = load i32, i32* %b, align 4
  %0 = icmp eq i32 %a2, %b3
  %1 = zext i1 %0 to i32
  %a4 = load i32, i32* %a, align 4
  %2 = icmp eq i32 %a4, 1
  %3 = zext i1 %2 to i32
  %4 = trunc i32 %1 to i1
  %5 = trunc i32 %3 to i1
  %6 = and i1 %4, %5
  %7 = zext i1 %6 to i32
  store i32 %7, i32* %aBoolean, align 4
  %aBoolean5 = load i32, i32* %aBoolean, align 4
  %8 = trunc i32 %aBoolean5 to i1
  %9 = xor i1 %8, true
  %10 = zext i1 %9 to i32
  %11 = trunc i32 %10 to i1
  br i1 %11, label %bTrue, label %bContinue

bTrue:                                            ; preds = %entry
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @3, i32 0, i32 0))
  br label %bContinue

bContinue:                                        ; preds = %bTrue, %entry
  %a1 = alloca i32, align 4
  store i32 1, i32* %a1, align 4
  %b16 = alloca i32, align 4
  %c1 = alloca i32, align 4
  store i32 2, i32* %c1, align 4
  %a27 = alloca i32, align 4
  store i32 1, i32* %a27, align 4
  %b2 = alloca i32, align 4
  store i32 0, i32* %b2, align 4
  %a210 = load i32, i32* %a27, align 4
  %b211 = load i32, i32* %b2, align 4
  %12 = trunc i32 %b211 to i1
  %13 = xor i1 %12, true
  %14 = zext i1 %13 to i32
  %15 = trunc i32 %a210 to i1
  %16 = trunc i32 %14 to i1
  %17 = and i1 %15, %16
  %18 = zext i1 %17 to i32
  %a112 = load i32, i32* %a1, align 4
  %19 = icmp eq i32 %a112, 1
  %20 = zext i1 %19 to i32
  %21 = trunc i32 %18 to i1
  %22 = trunc i32 %20 to i1
  %23 = and i1 %21, %22
  %24 = zext i1 %23 to i32
  %c113 = load i32, i32* %c1, align 4
  %25 = icmp eq i32 %c113, 2
  %26 = zext i1 %25 to i32
  %27 = trunc i32 %24 to i1
  %28 = trunc i32 %26 to i1
  %29 = and i1 %27, %28
  %30 = zext i1 %29 to i32
  %31 = trunc i32 %30 to i1
  %32 = xor i1 %31, true
  %33 = zext i1 %32 to i32
  %34 = trunc i32 %33 to i1
  br i1 %34, label %bTrue8, label %bContinue9

bTrue8:                                           ; preds = %bContinue
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @4, i32 0, i32 0))
  br label %bContinue9

bContinue9:                                       ; preds = %bTrue8, %bContinue
  %arr = alloca [5 x i32], align 4
  %35 = icmp eq i32 5, 5
  %36 = zext i1 %35 to i32
  %37 = trunc i32 %36 to i1
  %38 = xor i1 %37, true
  %39 = zext i1 %38 to i32
  %40 = trunc i32 %39 to i1
  br i1 %40, label %bTrue14, label %bContinue15

bTrue14:                                          ; preds = %bContinue9
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @5, i32 0, i32 0))
  br label %bContinue15

bContinue15:                                      ; preds = %bTrue14, %bContinue9
  %41 = mul nsw i32 4, 10
  %42 = add nsw i32 2, %41
  store i32 %42, i32* %a, align 4
  %a18 = load i32, i32* %a, align 4
  %43 = icmp eq i32 %a18, 42
  %44 = zext i1 %43 to i32
  %45 = trunc i32 %44 to i1
  %46 = xor i1 %45, true
  %47 = zext i1 %46 to i32
  %48 = trunc i32 %47 to i1
  br i1 %48, label %bTrue16, label %bContinue17

bTrue16:                                          ; preds = %bContinue15
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @6, i32 0, i32 0))
  br label %bContinue17

bContinue17:                                      ; preds = %bTrue16, %bContinue15
  %49 = sdiv i32 2, 2
  %50 = add nsw i32 2, %49
  store i32 %50, i32* %a, align 4
  %a21 = load i32, i32* %a, align 4
  %51 = icmp eq i32 %a21, 3
  %52 = zext i1 %51 to i32
  %53 = trunc i32 %52 to i1
  %54 = xor i1 %53, true
  %55 = zext i1 %54 to i32
  %56 = trunc i32 %55 to i1
  br i1 %56, label %bTrue19, label %bContinue20

bTrue19:                                          ; preds = %bContinue17
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @7, i32 0, i32 0))
  br label %bContinue20

bContinue20:                                      ; preds = %bTrue19, %bContinue17
  %57 = sdiv i32 2, 2
  %58 = sub nsw i32 2, %57
  store i32 %58, i32* %a, align 4
  %a24 = load i32, i32* %a, align 4
  %59 = icmp eq i32 %a24, 1
  %60 = zext i1 %59 to i32
  %61 = trunc i32 %60 to i1
  %62 = xor i1 %61, true
  %63 = zext i1 %62 to i32
  %64 = trunc i32 %63 to i1
  br i1 %64, label %bTrue22, label %bContinue23

bTrue22:                                          ; preds = %bContinue20
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @8, i32 0, i32 0))
  br label %bContinue23

bContinue23:                                      ; preds = %bTrue22, %bContinue20
  %sum = alloca i32, align 4
  store i32 1, i32* %sum, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i25 = load i32, i32* %i, align 4
  %65 = icmp slt i32 %i25, 5
  %66 = zext i1 %65 to i32
  %67 = trunc i32 %66 to i1
  br i1 %67, label %lTrue, label %lContinue

lTrue:                                            ; preds = %lTrue, %bContinue23
  %sum26 = load i32, i32* %sum, align 4
  %68 = mul nsw i32 %sum26, 2
  store i32 %68, i32* %sum, align 4
  %i27 = load i32, i32* %i, align 4
  %69 = add nsw i32 %i27, 1
  store i32 %69, i32* %i, align 4
  %i28 = load i32, i32* %i, align 4
  %70 = icmp slt i32 %i28, 5
  %71 = zext i1 %70 to i32
  %72 = trunc i32 %71 to i1
  br i1 %72, label %lTrue, label %lContinue

lContinue:                                        ; preds = %lTrue, %bContinue23
  %i31 = load i32, i32* %i, align 4
  %73 = icmp eq i32 %i31, 5
  %74 = zext i1 %73 to i32
  %sum32 = load i32, i32* %sum, align 4
  %75 = icmp eq i32 %sum32, 32
  %76 = zext i1 %75 to i32
  %77 = trunc i32 %74 to i1
  %78 = trunc i32 %76 to i1
  %79 = and i1 %77, %78
  %80 = zext i1 %79 to i32
  %81 = trunc i32 %80 to i1
  %82 = xor i1 %81, true
  %83 = zext i1 %82 to i32
  %84 = trunc i32 %83 to i1
  br i1 %84, label %bTrue29, label %bContinue30

bTrue29:                                          ; preds = %lContinue
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @9, i32 0, i32 0))
  br label %bContinue30

bContinue30:                                      ; preds = %bTrue29, %lContinue
  %sum2 = alloca i32, align 4
  store i32 1, i32* %sum2, align 4
  %i2 = alloca i32, align 4
  store i32 0, i32* %i2, align 4
  %j2 = alloca i32, align 4
  store i32 0, i32* %j2, align 4
  %i235 = load i32, i32* %i2, align 4
  %85 = icmp slt i32 %i235, 5
  %86 = zext i1 %85 to i32
  %87 = trunc i32 %86 to i1
  br i1 %87, label %lTrue33, label %lContinue34

lTrue33:                                          ; preds = %lContinue37, %bContinue30
  store i32 0, i32* %j2, align 4
  %j238 = load i32, i32* %j2, align 4
  %88 = icmp slt i32 %j238, 5
  %89 = zext i1 %88 to i32
  %90 = trunc i32 %89 to i1
  br i1 %90, label %lTrue36, label %lContinue37

lContinue34:                                      ; preds = %lContinue37, %bContinue30
  %i246 = load i32, i32* %i2, align 4
  %91 = icmp eq i32 %i246, 5
  %92 = zext i1 %91 to i32
  %j247 = load i32, i32* %j2, align 4
  %93 = icmp eq i32 %j247, 5
  %94 = zext i1 %93 to i32
  %95 = trunc i32 %92 to i1
  %96 = trunc i32 %94 to i1
  %97 = and i1 %95, %96
  %98 = zext i1 %97 to i32
  %sum248 = load i32, i32* %sum2, align 4
  %99 = icmp eq i32 %sum248, 51
  %100 = zext i1 %99 to i32
  %101 = trunc i32 %98 to i1
  %102 = trunc i32 %100 to i1
  %103 = and i1 %101, %102
  %104 = zext i1 %103 to i32
  %105 = trunc i32 %104 to i1
  %106 = xor i1 %105, true
  %107 = zext i1 %106 to i32
  %108 = trunc i32 %107 to i1
  br i1 %108, label %bTrue44, label %bContinue45

lTrue36:                                          ; preds = %lTrue36, %lTrue33
  %sum239 = load i32, i32* %sum2, align 4
  %109 = add nsw i32 %sum239, 2
  store i32 %109, i32* %sum2, align 4
  %j240 = load i32, i32* %j2, align 4
  %110 = add nsw i32 %j240, 1
  store i32 %110, i32* %j2, align 4
  %j241 = load i32, i32* %j2, align 4
  %111 = icmp slt i32 %j241, 5
  %112 = zext i1 %111 to i32
  %113 = trunc i32 %112 to i1
  br i1 %113, label %lTrue36, label %lContinue37

lContinue37:                                      ; preds = %lTrue36, %lTrue33
  %i242 = load i32, i32* %i2, align 4
  %114 = add nsw i32 %i242, 1
  store i32 %114, i32* %i2, align 4
  %i243 = load i32, i32* %i2, align 4
  %115 = icmp slt i32 %i243, 5
  %116 = zext i1 %115 to i32
  %117 = trunc i32 %116 to i1
  br i1 %117, label %lTrue33, label %lContinue34

bTrue44:                                          ; preds = %lContinue34
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @10, i32 0, i32 0))
  br label %bContinue45

bContinue45:                                      ; preds = %bTrue44, %lContinue34
  %ifvar = alloca i32, align 4
  store i32 0, i32* %ifvar, align 4
  %118 = trunc i32 1 to i1
  br i1 %118, label %bTrue49, label %bContinue50

bTrue49:                                          ; preds = %bContinue45
  %ifvar51 = load i32, i32* %ifvar, align 4
  %119 = add nsw i32 %ifvar51, 1
  store i32 %119, i32* %ifvar, align 4
  br label %bContinue50

bContinue50:                                      ; preds = %bTrue49, %bContinue45
  %120 = trunc i32 0 to i1
  br i1 %120, label %bTrue52, label %bContinue53

bTrue52:                                          ; preds = %bContinue50
  %ifvar54 = load i32, i32* %ifvar, align 4
  %121 = add nsw i32 %ifvar54, 1
  store i32 %121, i32* %ifvar, align 4
  br label %bContinue53

bContinue53:                                      ; preds = %bTrue52, %bContinue50
  %122 = trunc i32 1 to i1
  br i1 %122, label %bTrue55, label %bFalse

bTrue55:                                          ; preds = %bContinue53
  %ifvar57 = load i32, i32* %ifvar, align 4
  %123 = add nsw i32 %ifvar57, 10
  store i32 %123, i32* %ifvar, align 4
  br label %bContinue56

bFalse:                                           ; preds = %bContinue53
  %ifvar58 = load i32, i32* %ifvar, align 4
  %124 = add nsw i32 %ifvar58, 20
  store i32 %124, i32* %ifvar, align 4
  br label %bContinue56

bContinue56:                                      ; preds = %bFalse, %bTrue55
  %125 = trunc i32 0 to i1
  br i1 %125, label %bTrue59, label %bFalse60

bTrue59:                                          ; preds = %bContinue56
  %ifvar62 = load i32, i32* %ifvar, align 4
  %126 = add nsw i32 %ifvar62, 100
  store i32 %126, i32* %ifvar, align 4
  br label %bContinue61

bFalse60:                                         ; preds = %bContinue56
  %ifvar63 = load i32, i32* %ifvar, align 4
  %127 = add nsw i32 %ifvar63, 200
  store i32 %127, i32* %ifvar, align 4
  br label %bContinue61

bContinue61:                                      ; preds = %bFalse60, %bTrue59
  %ifvar66 = load i32, i32* %ifvar, align 4
  %128 = icmp eq i32 %ifvar66, 211
  %129 = zext i1 %128 to i32
  %130 = trunc i32 %129 to i1
  %131 = xor i1 %130, true
  %132 = zext i1 %131 to i32
  %133 = trunc i32 %132 to i1
  br i1 %133, label %bTrue64, label %bContinue65

bTrue64:                                          ; preds = %bContinue61
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @11, i32 0, i32 0))
  br label %bContinue65

bContinue65:                                      ; preds = %bTrue64, %bContinue61
  %x = alloca i32, align 4
  %sign1 = alloca i32, align 4
  %sign2 = alloca i32, align 4
  %sign3 = alloca i32, align 4
  %134 = sub nsw i32 0, 1
  store i32 %134, i32* %x, align 4
  %x68 = load i32, i32* %x, align 4
  %135 = icmp slt i32 %x68, 0
  %136 = zext i1 %135 to i32
  %137 = trunc i32 %136 to i1
  br i1 %137, label %SelectPt0, label %FSelectPt0

SelectPt0:                                        ; preds = %bContinue65
  %138 = sub nsw i32 0, 1
  store i32 %138, i32* %sign1, align 4
  br label %bContinue67

FSelectPt0:                                       ; preds = %bContinue65
  %x69 = load i32, i32* %x, align 4
  %139 = icmp eq i32 %x69, 0
  %140 = zext i1 %139 to i32
  %141 = trunc i32 %140 to i1
  br i1 %141, label %SelectPt1, label %FSelectPt1

SelectPt1:                                        ; preds = %FSelectPt0
  store i32 0, i32* %sign1, align 4
  br label %bContinue67

FSelectPt1:                                       ; preds = %FSelectPt0
  %x70 = load i32, i32* %x, align 4
  %142 = icmp sgt i32 %x70, 0
  %143 = zext i1 %142 to i32
  %144 = trunc i32 %143 to i1
  br i1 %144, label %SelectPt2, label %FSelectPt2

SelectPt2:                                        ; preds = %FSelectPt1
  store i32 7, i32* %sign1, align 4
  br label %bContinue67

FSelectPt2:                                       ; preds = %FSelectPt1
  br label %bContinue67

bContinue67:                                      ; preds = %FSelectPt2, %SelectPt2, %SelectPt1, %SelectPt0
  store i32 0, i32* %x, align 4
  %x78 = load i32, i32* %x, align 4
  %145 = icmp slt i32 %x78, 0
  %146 = zext i1 %145 to i32
  %147 = trunc i32 %146 to i1
  br i1 %147, label %SelectPt071, label %FSelectPt072

SelectPt071:                                      ; preds = %bContinue67
  %148 = sub nsw i32 0, 1
  store i32 %148, i32* %sign2, align 4
  br label %bContinue77

FSelectPt072:                                     ; preds = %bContinue67
  %x79 = load i32, i32* %x, align 4
  %149 = icmp eq i32 %x79, 0
  %150 = zext i1 %149 to i32
  %151 = trunc i32 %150 to i1
  br i1 %151, label %SelectPt173, label %FSelectPt174

SelectPt173:                                      ; preds = %FSelectPt072
  store i32 0, i32* %sign2, align 4
  br label %bContinue77

FSelectPt174:                                     ; preds = %FSelectPt072
  %x80 = load i32, i32* %x, align 4
  %152 = icmp sgt i32 %x80, 0
  %153 = zext i1 %152 to i32
  %154 = trunc i32 %153 to i1
  br i1 %154, label %SelectPt275, label %FSelectPt276

SelectPt275:                                      ; preds = %FSelectPt174
  store i32 1, i32* %sign2, align 4
  br label %bContinue77

FSelectPt276:                                     ; preds = %FSelectPt174
  br label %bContinue77

bContinue77:                                      ; preds = %FSelectPt276, %SelectPt275, %SelectPt173, %SelectPt071
  store i32 10, i32* %x, align 4
  %x88 = load i32, i32* %x, align 4
  %155 = icmp slt i32 %x88, 0
  %156 = zext i1 %155 to i32
  %157 = trunc i32 %156 to i1
  br i1 %157, label %SelectPt081, label %FSelectPt082

SelectPt081:                                      ; preds = %bContinue77
  %158 = sub nsw i32 0, 1
  store i32 %158, i32* %sign3, align 4
  br label %bContinue87

FSelectPt082:                                     ; preds = %bContinue77
  %x89 = load i32, i32* %x, align 4
  %159 = icmp eq i32 %x89, 0
  %160 = zext i1 %159 to i32
  %161 = trunc i32 %160 to i1
  br i1 %161, label %SelectPt183, label %FSelectPt184

SelectPt183:                                      ; preds = %FSelectPt082
  store i32 0, i32* %sign3, align 4
  br label %bContinue87

FSelectPt184:                                     ; preds = %FSelectPt082
  %x90 = load i32, i32* %x, align 4
  %162 = icmp sgt i32 %x90, 0
  %163 = zext i1 %162 to i32
  %164 = trunc i32 %163 to i1
  br i1 %164, label %SelectPt285, label %FSelectPt286

SelectPt285:                                      ; preds = %FSelectPt184
  store i32 1, i32* %sign3, align 4
  br label %bContinue87

FSelectPt286:                                     ; preds = %FSelectPt184
  br label %bContinue87

bContinue87:                                      ; preds = %FSelectPt286, %SelectPt285, %SelectPt183, %SelectPt081
  %sign193 = load i32, i32* %sign1, align 4
  %165 = sub nsw i32 0, 1
  %166 = icmp eq i32 %sign193, %165
  %167 = zext i1 %166 to i32
  %sign294 = load i32, i32* %sign2, align 4
  %168 = icmp eq i32 %sign294, 0
  %169 = zext i1 %168 to i32
  %170 = trunc i32 %167 to i1
  %171 = trunc i32 %169 to i1
  %172 = and i1 %170, %171
  %173 = zext i1 %172 to i32
  %sign395 = load i32, i32* %sign3, align 4
  %174 = icmp eq i32 %sign395, 1
  %175 = zext i1 %174 to i32
  %176 = trunc i32 %173 to i1
  %177 = trunc i32 %175 to i1
  %178 = and i1 %176, %177
  %179 = zext i1 %178 to i32
  %180 = trunc i32 %179 to i1
  %181 = xor i1 %180, true
  %182 = zext i1 %181 to i32
  %183 = trunc i32 %182 to i1
  br i1 %183, label %bTrue91, label %bContinue92

bTrue91:                                          ; preds = %bContinue87
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @12, i32 0, i32 0))
  br label %bContinue92

bContinue92:                                      ; preds = %bTrue91, %bContinue87
  %f1 = alloca i32, align 4
  %184 = call i32 @intf()
  store i32 %184, i32* %f1, align 4
  %f2 = alloca i32, align 4
  %anInt96 = load i32, i32* %anInt, align 4
  %185 = call i8* @strf()
  %186 = call i32 @boolf(i32 %anInt96, i32 1, i8* %185)
  store i32 %186, i32* %f2, align 4
  %s = alloca i8*, align 8
  %187 = call i8* @strf()
  store i8* %187, i8** %s, align 8
  %f199 = load i32, i32* %f1, align 4
  %188 = icmp eq i32 %f199, 3
  %189 = zext i1 %188 to i32
  %f2100 = load i32, i32* %f2, align 4
  %190 = trunc i32 %189 to i1
  %191 = trunc i32 %f2100 to i1
  %192 = and i1 %190, %191
  %193 = zext i1 %192 to i32
  %194 = trunc i32 %193 to i1
  %195 = xor i1 %194, true
  %196 = zext i1 %195 to i32
  %197 = trunc i32 %196 to i1
  br i1 %197, label %bTrue97, label %bContinue98

bTrue97:                                          ; preds = %bContinue92
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @13, i32 0, i32 0))
  br label %bContinue98

bContinue98:                                      ; preds = %bTrue97, %bContinue92
  %globalVar = load i32, i32* @globalVar, align 4
  %198 = icmp eq i32 %globalVar, 5
  %199 = zext i1 %198 to i32
  %200 = trunc i32 %199 to i1
  %201 = xor i1 %200, true
  %202 = zext i1 %201 to i32
  %203 = trunc i32 %202 to i1
  br i1 %203, label %bTrue101, label %bContinue102

bTrue101:                                         ; preds = %bContinue98
  call void @print(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @14, i32 0, i32 0))
  br label %bContinue102

bContinue102:                                     ; preds = %bTrue101, %bContinue98
  %anInt103 = load i32, i32* %anInt, align 4
  call void @testProc(i32 %anInt103, i32 1, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @15, i32 0, i32 0))
  %globalVar106 = load i32, i32* @globalVar, align 4
  %204 = icmp eq i32 %globalVar106, 3
  %205 = zext i1 %204 to i32
  %206 = trunc i32 %205 to i1
  %207 = xor i1 %206, true
  %208 = zext i1 %207 to i32
  %209 = trunc i32 %208 to i1
  br i1 %209, label %bTrue104, label %bContinue105

bTrue104:                                         ; preds = %bContinue102
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @16, i32 0, i32 0))
  br label %bContinue105

bContinue105:                                     ; preds = %bTrue104, %bContinue102
  call void @testProc2()
  %globalVar109 = load i32, i32* @globalVar, align 4
  %210 = icmp eq i32 %globalVar109, 320
  %211 = zext i1 %210 to i32
  %212 = trunc i32 %211 to i1
  %213 = xor i1 %212, true
  %214 = zext i1 %213 to i32
  %215 = trunc i32 %214 to i1
  br i1 %215, label %bTrue107, label %bContinue108

bTrue107:                                         ; preds = %bContinue105
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @17, i32 0, i32 0))
  br label %bContinue108

bContinue108:                                     ; preds = %bTrue107, %bContinue105
  %blockTest = alloca i32, align 4
  store i32 5, i32* %blockTest, align 4
  %blockTest110 = alloca i32, align 4
  store i32 7, i32* %blockTest110, align 4
  %blockTest113 = load i32, i32* %blockTest110, align 4
  %216 = icmp eq i32 %blockTest113, 7
  %217 = zext i1 %216 to i32
  %218 = trunc i32 %217 to i1
  %219 = xor i1 %218, true
  %220 = zext i1 %219 to i32
  %221 = trunc i32 %220 to i1
  br i1 %221, label %bTrue111, label %bContinue112

bTrue111:                                         ; preds = %bContinue108
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @18, i32 0, i32 0))
  br label %bContinue112

bContinue112:                                     ; preds = %bTrue111, %bContinue108
  %blockTest116 = load i32, i32* %blockTest, align 4
  %222 = icmp eq i32 %blockTest116, 5
  %223 = zext i1 %222 to i32
  %224 = trunc i32 %223 to i1
  %225 = xor i1 %224, true
  %226 = zext i1 %225 to i32
  %227 = trunc i32 %226 to i1
  br i1 %227, label %bTrue114, label %bContinue115

bTrue114:                                         ; preds = %bContinue112
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @19, i32 0, i32 0))
  br label %bContinue115

bContinue115:                                     ; preds = %bTrue114, %bContinue112
  %228 = icmp ne i32 1, 1
  %229 = zext i1 %228 to i32
  %230 = trunc i32 %229 to i1
  br i1 %230, label %bTrue117, label %bContinue118

bTrue117:                                         ; preds = %bContinue115
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @20, i32 0, i32 0))
  br label %bContinue118

bContinue118:                                     ; preds = %bTrue117, %bContinue115
  %231 = icmp ne i32 1, 2
  %232 = zext i1 %231 to i32
  %233 = trunc i32 %232 to i1
  %234 = xor i1 %233, true
  %235 = zext i1 %234 to i32
  %236 = trunc i32 %235 to i1
  br i1 %236, label %bTrue119, label %bContinue120

bTrue119:                                         ; preds = %bContinue118
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @21, i32 0, i32 0))
  br label %bContinue120

bContinue120:                                     ; preds = %bTrue119, %bContinue118
  %237 = trunc i32 1 to i1
  %238 = xor i1 %237, true
  %239 = zext i1 %238 to i32
  %240 = trunc i32 %239 to i1
  br i1 %240, label %bTrue121, label %bContinue122

bTrue121:                                         ; preds = %bContinue120
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @22, i32 0, i32 0))
  br label %bContinue122

bContinue122:                                     ; preds = %bTrue121, %bContinue120
  %241 = trunc i32 0 to i1
  %242 = xor i1 %241, true
  %243 = zext i1 %242 to i32
  %244 = trunc i32 %243 to i1
  %245 = xor i1 %244, true
  %246 = zext i1 %245 to i32
  %247 = trunc i32 %246 to i1
  br i1 %247, label %bTrue123, label %bContinue124

bTrue123:                                         ; preds = %bContinue122
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @23, i32 0, i32 0))
  br label %bContinue124

bContinue124:                                     ; preds = %bTrue123, %bContinue122
  %248 = icmp eq i32 1, 2
  %249 = zext i1 %248 to i32
  %250 = trunc i32 %249 to i1
  br i1 %250, label %bTrue125, label %bContinue126

bTrue125:                                         ; preds = %bContinue124
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @24, i32 0, i32 0))
  br label %bContinue126

bContinue126:                                     ; preds = %bTrue125, %bContinue124
  %251 = icmp eq i32 1, 1
  %252 = zext i1 %251 to i32
  %253 = trunc i32 %252 to i1
  %254 = xor i1 %253, true
  %255 = zext i1 %254 to i32
  %256 = trunc i32 %255 to i1
  br i1 %256, label %bTrue127, label %bContinue128

bTrue127:                                         ; preds = %bContinue126
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @25, i32 0, i32 0))
  br label %bContinue128

bContinue128:                                     ; preds = %bTrue127, %bContinue126
  %257 = icmp sgt i32 1, 1
  %258 = zext i1 %257 to i32
  %259 = trunc i32 %258 to i1
  br i1 %259, label %bTrue129, label %bContinue130

bTrue129:                                         ; preds = %bContinue128
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @26, i32 0, i32 0))
  br label %bContinue130

bContinue130:                                     ; preds = %bTrue129, %bContinue128
  %260 = icmp sgt i32 1, 0
  %261 = zext i1 %260 to i32
  %262 = trunc i32 %261 to i1
  %263 = xor i1 %262, true
  %264 = zext i1 %263 to i32
  %265 = trunc i32 %264 to i1
  br i1 %265, label %bTrue131, label %bContinue132

bTrue131:                                         ; preds = %bContinue130
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @27, i32 0, i32 0))
  br label %bContinue132

bContinue132:                                     ; preds = %bTrue131, %bContinue130
  %266 = icmp slt i32 1, 1
  %267 = zext i1 %266 to i32
  %268 = trunc i32 %267 to i1
  br i1 %268, label %bTrue133, label %bContinue134

bTrue133:                                         ; preds = %bContinue132
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @28, i32 0, i32 0))
  br label %bContinue134

bContinue134:                                     ; preds = %bTrue133, %bContinue132
  %269 = icmp slt i32 1, 2
  %270 = zext i1 %269 to i32
  %271 = trunc i32 %270 to i1
  %272 = xor i1 %271, true
  %273 = zext i1 %272 to i32
  %274 = trunc i32 %273 to i1
  br i1 %274, label %bTrue135, label %bContinue136

bTrue135:                                         ; preds = %bContinue134
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @29, i32 0, i32 0))
  br label %bContinue136

bContinue136:                                     ; preds = %bTrue135, %bContinue134
  %275 = icmp sge i32 1, 2
  %276 = zext i1 %275 to i32
  %277 = trunc i32 %276 to i1
  br i1 %277, label %bTrue137, label %bContinue138

bTrue137:                                         ; preds = %bContinue136
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @30, i32 0, i32 0))
  br label %bContinue138

bContinue138:                                     ; preds = %bTrue137, %bContinue136
  %278 = icmp sge i32 1, 1
  %279 = zext i1 %278 to i32
  %280 = trunc i32 %279 to i1
  %281 = xor i1 %280, true
  %282 = zext i1 %281 to i32
  %283 = trunc i32 %282 to i1
  br i1 %283, label %bTrue139, label %bContinue140

bTrue139:                                         ; preds = %bContinue138
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @31, i32 0, i32 0))
  br label %bContinue140

bContinue140:                                     ; preds = %bTrue139, %bContinue138
  %284 = icmp sle i32 1, 0
  %285 = zext i1 %284 to i32
  %286 = trunc i32 %285 to i1
  br i1 %286, label %bTrue141, label %bContinue142

bTrue141:                                         ; preds = %bContinue140
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @32, i32 0, i32 0))
  br label %bContinue142

bContinue142:                                     ; preds = %bTrue141, %bContinue140
  %287 = icmp sle i32 1, 1
  %288 = zext i1 %287 to i32
  %289 = trunc i32 %288 to i1
  %290 = xor i1 %289, true
  %291 = zext i1 %290 to i32
  %292 = trunc i32 %291 to i1
  br i1 %292, label %bTrue143, label %bContinue144

bTrue143:                                         ; preds = %bContinue142
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @33, i32 0, i32 0))
  br label %bContinue144

bContinue144:                                     ; preds = %bTrue143, %bContinue142
  %293 = trunc i32 1 to i1
  %294 = trunc i32 1 to i1
  %295 = and i1 %293, %294
  %296 = zext i1 %295 to i32
  %297 = trunc i32 %296 to i1
  %298 = xor i1 %297, true
  %299 = zext i1 %298 to i32
  %300 = trunc i32 %299 to i1
  br i1 %300, label %bTrue145, label %bContinue146

bTrue145:                                         ; preds = %bContinue144
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @34, i32 0, i32 0))
  br label %bContinue146

bContinue146:                                     ; preds = %bTrue145, %bContinue144
  %301 = trunc i32 1 to i1
  %302 = trunc i32 0 to i1
  %303 = and i1 %301, %302
  %304 = zext i1 %303 to i32
  %305 = trunc i32 %304 to i1
  br i1 %305, label %bTrue147, label %bContinue148

bTrue147:                                         ; preds = %bContinue146
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @35, i32 0, i32 0))
  br label %bContinue148

bContinue148:                                     ; preds = %bTrue147, %bContinue146
  %306 = trunc i32 0 to i1
  %307 = trunc i32 1 to i1
  %308 = and i1 %306, %307
  %309 = zext i1 %308 to i32
  %310 = trunc i32 %309 to i1
  br i1 %310, label %bTrue149, label %bContinue150

bTrue149:                                         ; preds = %bContinue148
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @36, i32 0, i32 0))
  br label %bContinue150

bContinue150:                                     ; preds = %bTrue149, %bContinue148
  %311 = trunc i32 0 to i1
  %312 = trunc i32 0 to i1
  %313 = and i1 %311, %312
  %314 = zext i1 %313 to i32
  %315 = trunc i32 %314 to i1
  br i1 %315, label %bTrue151, label %bContinue152

bTrue151:                                         ; preds = %bContinue150
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @37, i32 0, i32 0))
  br label %bContinue152

bContinue152:                                     ; preds = %bTrue151, %bContinue150
  %316 = trunc i32 1 to i1
  %317 = trunc i32 1 to i1
  %318 = or i1 %316, %317
  %319 = zext i1 %318 to i32
  %320 = trunc i32 %319 to i1
  %321 = xor i1 %320, true
  %322 = zext i1 %321 to i32
  %323 = trunc i32 %322 to i1
  br i1 %323, label %bTrue153, label %bContinue154

bTrue153:                                         ; preds = %bContinue152
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @38, i32 0, i32 0))
  br label %bContinue154

bContinue154:                                     ; preds = %bTrue153, %bContinue152
  %324 = trunc i32 1 to i1
  %325 = trunc i32 0 to i1
  %326 = or i1 %324, %325
  %327 = zext i1 %326 to i32
  %328 = trunc i32 %327 to i1
  %329 = xor i1 %328, true
  %330 = zext i1 %329 to i32
  %331 = trunc i32 %330 to i1
  br i1 %331, label %bTrue155, label %bContinue156

bTrue155:                                         ; preds = %bContinue154
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @39, i32 0, i32 0))
  br label %bContinue156

bContinue156:                                     ; preds = %bTrue155, %bContinue154
  %332 = trunc i32 0 to i1
  %333 = trunc i32 1 to i1
  %334 = or i1 %332, %333
  %335 = zext i1 %334 to i32
  %336 = trunc i32 %335 to i1
  %337 = xor i1 %336, true
  %338 = zext i1 %337 to i32
  %339 = trunc i32 %338 to i1
  br i1 %339, label %bTrue157, label %bContinue158

bTrue157:                                         ; preds = %bContinue156
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @40, i32 0, i32 0))
  br label %bContinue158

bContinue158:                                     ; preds = %bTrue157, %bContinue156
  %340 = trunc i32 0 to i1
  %341 = trunc i32 0 to i1
  %342 = or i1 %340, %341
  %343 = zext i1 %342 to i32
  %344 = trunc i32 %343 to i1
  br i1 %344, label %bTrue159, label %bContinue160

bTrue159:                                         ; preds = %bContinue158
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @41, i32 0, i32 0))
  br label %bContinue160

bContinue160:                                     ; preds = %bTrue159, %bContinue158
  %345 = trunc i32 0 to i1
  %346 = trunc i32 0 to i1
  %347 = and i1 %345, %346
  %348 = zext i1 %347 to i32
  %349 = trunc i32 1 to i1
  %350 = trunc i32 %348 to i1
  %351 = or i1 %349, %350
  %352 = zext i1 %351 to i32
  %353 = trunc i32 %352 to i1
  %354 = xor i1 %353, true
  %355 = zext i1 %354 to i32
  %356 = trunc i32 %355 to i1
  br i1 %356, label %bTrue161, label %bContinue162

bTrue161:                                         ; preds = %bContinue160
  call void @print(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @42, i32 0, i32 0))
  br label %bContinue162

bContinue162:                                     ; preds = %bTrue161, %bContinue160
  %357 = trunc i32 0 to i1
  %358 = trunc i32 0 to i1
  %359 = and i1 %357, %358
  %360 = zext i1 %359 to i32
  %361 = trunc i32 %360 to i1
  %362 = trunc i32 1 to i1
  %363 = or i1 %361, %362
  %364 = zext i1 %363 to i32
  %365 = trunc i32 %364 to i1
  %366 = xor i1 %365, true
  %367 = zext i1 %366 to i32
  %368 = trunc i32 %367 to i1
  br i1 %368, label %bTrue163, label %bContinue164

bTrue163:                                         ; preds = %bContinue162
  call void @print(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @43, i32 0, i32 0))
  br label %bContinue164

bContinue164:                                     ; preds = %bTrue163, %bContinue162
  %369 = trunc i32 0 to i1
  %370 = trunc i32 1 to i1
  %371 = or i1 %369, %370
  %372 = zext i1 %371 to i32
  %373 = trunc i32 0 to i1
  %374 = trunc i32 %372 to i1
  %375 = and i1 %373, %374
  %376 = zext i1 %375 to i32
  %377 = trunc i32 %376 to i1
  br i1 %377, label %bTrue165, label %bContinue166

bTrue165:                                         ; preds = %bContinue164
  call void @print(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @44, i32 0, i32 0))
  br label %bContinue166

bContinue166:                                     ; preds = %bTrue165, %bContinue164
  %378 = mul nsw i32 3, 7
  %379 = add nsw i32 2, %378
  %380 = icmp ne i32 %379, 23
  %381 = zext i1 %380 to i32
  %382 = trunc i32 %381 to i1
  br i1 %382, label %bTrue167, label %bContinue168

bTrue167:                                         ; preds = %bContinue166
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @45, i32 0, i32 0))
  br label %bContinue168

bContinue168:                                     ; preds = %bTrue167, %bContinue166
  %383 = add nsw i32 2, 3
  %384 = mul nsw i32 %383, 7
  %385 = icmp ne i32 %384, 35
  %386 = zext i1 %385 to i32
  %387 = trunc i32 %386 to i1
  br i1 %387, label %bTrue169, label %bContinue170

bTrue169:                                         ; preds = %bContinue168
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @46, i32 0, i32 0))
  br label %bContinue170

bContinue170:                                     ; preds = %bTrue169, %bContinue168
  %388 = mul nsw i32 2, 3
  %389 = add nsw i32 %388, 7
  %390 = icmp ne i32 %389, 13
  %391 = zext i1 %390 to i32
  %392 = trunc i32 %391 to i1
  br i1 %392, label %bTrue171, label %bContinue172

bTrue171:                                         ; preds = %bContinue170
  call void @print(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @47, i32 0, i32 0))
  br label %bContinue172

bContinue172:                                     ; preds = %bTrue171, %bContinue170
  %393 = add nsw i32 3, 7
  %394 = mul nsw i32 2, %393
  %395 = icmp ne i32 %394, 20
  %396 = zext i1 %395 to i32
  %397 = trunc i32 %396 to i1
  br i1 %397, label %bTrue173, label %bContinue174

bTrue173:                                         ; preds = %bContinue172
  call void @print(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @48, i32 0, i32 0))
  br label %bContinue174

bContinue174:                                     ; preds = %bTrue173, %bContinue172
  %398 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 2
  %399 = load i32, i32* %398, align 4
  store i32 %399, i32* %x, align 4
  %400 = add nsw i32 2, 1
  %401 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 %400
  %402 = load i32, i32* %401, align 4
  %403 = icmp eq i32 %402, 3
  %404 = zext i1 %403 to i32
  %405 = trunc i32 %404 to i1
  br i1 %405, label %bTrue175, label %bContinue176

bTrue175:                                         ; preds = %bContinue174
  call void @print(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @49, i32 0, i32 0))
  br label %bContinue176

bContinue176:                                     ; preds = %bTrue175, %bContinue174
  store i32 3, i32* %x, align 4
  %x177 = load i32, i32* %x, align 4
  %406 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 %x177
  %407 = load i32, i32* %406, align 4
  store i32 3, i32* %406, align 4
  %408 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 3
  %409 = load i32, i32* %408, align 4
  %410 = icmp eq i32 %409, 3
  %411 = zext i1 %410 to i32
  %412 = trunc i32 %411 to i1
  %413 = xor i1 %412, true
  %414 = zext i1 %413 to i32
  %415 = trunc i32 %414 to i1
  br i1 %415, label %bTrue178, label %bContinue179

bTrue178:                                         ; preds = %bContinue176
  call void @print(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @50, i32 0, i32 0))
  br label %bContinue179

bContinue179:                                     ; preds = %bTrue178, %bContinue176
  call void @print(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @51, i32 0, i32 0))
  ret i32 5
}
