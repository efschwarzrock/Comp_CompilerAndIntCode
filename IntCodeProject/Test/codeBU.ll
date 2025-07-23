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
@14 = private unnamed_addr constant [13 x i8] c"\22Error 9 %d\22\00", align 1
@15 = private unnamed_addr constant [5 x i8] c"\22we\22\00", align 1
@16 = private unnamed_addr constant [11 x i8] c"\22Error 10\22\00", align 1
@17 = private unnamed_addr constant [14 x i8] c"\22Error 11 %d\22\00", align 1
@18 = private unnamed_addr constant [12 x i8] c"\22Error 12a\22\00", align 1
@19 = private unnamed_addr constant [15 x i8] c"\22Error 12b %d\22\00", align 1
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

declare i32 @printf(i8*, ...)

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
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @0, i32 0, i32 0))
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
  %13 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @2, i32 0, i32 0))
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
  %12 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @3, i32 0, i32 0))
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
  %13 = trunc i32 %b211 to i1
  %14 = xor i1 %13, true
  %15 = zext i1 %14 to i32
  %16 = trunc i32 %a210 to i1
  %17 = trunc i32 %15 to i1
  %18 = and i1 %16, %17
  %19 = zext i1 %18 to i32
  %a112 = load i32, i32* %a1, align 4
  %20 = icmp eq i32 %a112, 1
  %21 = zext i1 %20 to i32
  %22 = trunc i32 %19 to i1
  %23 = trunc i32 %21 to i1
  %24 = and i1 %22, %23
  %25 = zext i1 %24 to i32
  %c113 = load i32, i32* %c1, align 4
  %26 = icmp eq i32 %c113, 2
  %27 = zext i1 %26 to i32
  %28 = trunc i32 %25 to i1
  %29 = trunc i32 %27 to i1
  %30 = and i1 %28, %29
  %31 = zext i1 %30 to i32
  %32 = trunc i32 %31 to i1
  %33 = xor i1 %32, true
  %34 = zext i1 %33 to i32
  %35 = trunc i32 %34 to i1
  br i1 %35, label %bTrue8, label %bContinue9

bTrue8:                                           ; preds = %bContinue
  %36 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @4, i32 0, i32 0))
  br label %bContinue9

bContinue9:                                       ; preds = %bTrue8, %bContinue
  %arr = alloca [5 x i32], align 4
  %37 = icmp eq i32 5, 5
  %38 = zext i1 %37 to i32
  %39 = trunc i32 %38 to i1
  %40 = xor i1 %39, true
  %41 = zext i1 %40 to i32
  %42 = trunc i32 %41 to i1
  br i1 %42, label %bTrue14, label %bContinue15

bTrue14:                                          ; preds = %bContinue9
  %43 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @5, i32 0, i32 0))
  br label %bContinue15

bContinue15:                                      ; preds = %bTrue14, %bContinue9
  %44 = mul nsw i32 4, 10
  %45 = add nsw i32 2, %44
  store i32 %45, i32* %a, align 4
  %a18 = load i32, i32* %a, align 4
  %46 = icmp eq i32 %a18, 42
  %47 = zext i1 %46 to i32
  %48 = trunc i32 %47 to i1
  %49 = xor i1 %48, true
  %50 = zext i1 %49 to i32
  %51 = trunc i32 %50 to i1
  br i1 %51, label %bTrue16, label %bContinue17

bTrue16:                                          ; preds = %bContinue15
  %52 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @6, i32 0, i32 0))
  br label %bContinue17

bContinue17:                                      ; preds = %bTrue16, %bContinue15
  %53 = sdiv i32 2, 2
  %54 = add nsw i32 2, %53
  store i32 %54, i32* %a, align 4
  %a21 = load i32, i32* %a, align 4
  %55 = icmp eq i32 %a21, 3
  %56 = zext i1 %55 to i32
  %57 = trunc i32 %56 to i1
  %58 = xor i1 %57, true
  %59 = zext i1 %58 to i32
  %60 = trunc i32 %59 to i1
  br i1 %60, label %bTrue19, label %bContinue20

bTrue19:                                          ; preds = %bContinue17
  %61 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @7, i32 0, i32 0))
  br label %bContinue20

bContinue20:                                      ; preds = %bTrue19, %bContinue17
  %62 = sdiv i32 2, 2
  %63 = sub nsw i32 2, %62
  store i32 %63, i32* %a, align 4
  %a24 = load i32, i32* %a, align 4
  %64 = icmp eq i32 %a24, 1
  %65 = zext i1 %64 to i32
  %66 = trunc i32 %65 to i1
  %67 = xor i1 %66, true
  %68 = zext i1 %67 to i32
  %69 = trunc i32 %68 to i1
  br i1 %69, label %bTrue22, label %bContinue23

bTrue22:                                          ; preds = %bContinue20
  %70 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @8, i32 0, i32 0))
  br label %bContinue23

bContinue23:                                      ; preds = %bTrue22, %bContinue20
  %sum = alloca i32, align 4
  store i32 1, i32* %sum, align 4
  %i = alloca i32, align 4
  store i32 0, i32* %i, align 4
  %i25 = load i32, i32* %i, align 4
  %71 = icmp slt i32 %i25, 5
  %72 = zext i1 %71 to i32
  %73 = trunc i32 %72 to i1
  br i1 %73, label %lTrue, label %lContinue

lTrue:                                            ; preds = %lTrue, %bContinue23
  %sum26 = load i32, i32* %sum, align 4
  %74 = mul nsw i32 %sum26, 2
  store i32 %74, i32* %sum, align 4
  %i27 = load i32, i32* %i, align 4
  %75 = add nsw i32 %i27, 1
  store i32 %75, i32* %i, align 4
  %i28 = load i32, i32* %i, align 4
  %76 = icmp slt i32 %i28, 5
  %77 = zext i1 %76 to i32
  %78 = trunc i32 %77 to i1
  br i1 %78, label %lTrue, label %lContinue

lContinue:                                        ; preds = %lTrue, %bContinue23
  %i31 = load i32, i32* %i, align 4
  %79 = icmp eq i32 %i31, 5
  %80 = zext i1 %79 to i32
  %sum32 = load i32, i32* %sum, align 4
  %81 = icmp eq i32 %sum32, 32
  %82 = zext i1 %81 to i32
  %83 = trunc i32 %80 to i1
  %84 = trunc i32 %82 to i1
  %85 = and i1 %83, %84
  %86 = zext i1 %85 to i32
  %87 = trunc i32 %86 to i1
  %88 = xor i1 %87, true
  %89 = zext i1 %88 to i32
  %90 = trunc i32 %89 to i1
  br i1 %90, label %bTrue29, label %bContinue30

bTrue29:                                          ; preds = %lContinue
  %91 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @9, i32 0, i32 0))
  br label %bContinue30

bContinue30:                                      ; preds = %bTrue29, %lContinue
  %sum2 = alloca i32, align 4
  store i32 1, i32* %sum2, align 4
  %i2 = alloca i32, align 4
  store i32 0, i32* %i2, align 4
  %j2 = alloca i32, align 4
  store i32 0, i32* %j2, align 4
  %i235 = load i32, i32* %i2, align 4
  %92 = icmp slt i32 %i235, 5
  %93 = zext i1 %92 to i32
  %94 = trunc i32 %93 to i1
  br i1 %94, label %lTrue33, label %lContinue34

lTrue33:                                          ; preds = %lContinue37, %bContinue30
  store i32 0, i32* %j2, align 4
  %j238 = load i32, i32* %j2, align 4
  %95 = icmp slt i32 %j238, 5
  %96 = zext i1 %95 to i32
  %97 = trunc i32 %96 to i1
  br i1 %97, label %lTrue36, label %lContinue37

lContinue34:                                      ; preds = %lContinue37, %bContinue30
  %i246 = load i32, i32* %i2, align 4
  %98 = icmp eq i32 %i246, 5
  %99 = zext i1 %98 to i32
  %j247 = load i32, i32* %j2, align 4
  %100 = icmp eq i32 %j247, 5
  %101 = zext i1 %100 to i32
  %102 = trunc i32 %99 to i1
  %103 = trunc i32 %101 to i1
  %104 = and i1 %102, %103
  %105 = zext i1 %104 to i32
  %sum248 = load i32, i32* %sum2, align 4
  %106 = icmp eq i32 %sum248, 51
  %107 = zext i1 %106 to i32
  %108 = trunc i32 %105 to i1
  %109 = trunc i32 %107 to i1
  %110 = and i1 %108, %109
  %111 = zext i1 %110 to i32
  %112 = trunc i32 %111 to i1
  %113 = xor i1 %112, true
  %114 = zext i1 %113 to i32
  %115 = trunc i32 %114 to i1
  br i1 %115, label %bTrue44, label %bContinue45

lTrue36:                                          ; preds = %lTrue36, %lTrue33
  %sum239 = load i32, i32* %sum2, align 4
  %116 = add nsw i32 %sum239, 2
  store i32 %116, i32* %sum2, align 4
  %j240 = load i32, i32* %j2, align 4
  %117 = add nsw i32 %j240, 1
  store i32 %117, i32* %j2, align 4
  %j241 = load i32, i32* %j2, align 4
  %118 = icmp slt i32 %j241, 5
  %119 = zext i1 %118 to i32
  %120 = trunc i32 %119 to i1
  br i1 %120, label %lTrue36, label %lContinue37

lContinue37:                                      ; preds = %lTrue36, %lTrue33
  %i242 = load i32, i32* %i2, align 4
  %121 = add nsw i32 %i242, 1
  store i32 %121, i32* %i2, align 4
  %i243 = load i32, i32* %i2, align 4
  %122 = icmp slt i32 %i243, 5
  %123 = zext i1 %122 to i32
  %124 = trunc i32 %123 to i1
  br i1 %124, label %lTrue33, label %lContinue34

bTrue44:                                          ; preds = %lContinue34
  %125 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @10, i32 0, i32 0))
  br label %bContinue45

bContinue45:                                      ; preds = %bTrue44, %lContinue34
  %ifvar = alloca i32, align 4
  store i32 0, i32* %ifvar, align 4
  %126 = trunc i32 1 to i1
  br i1 %126, label %bTrue49, label %bContinue50

bTrue49:                                          ; preds = %bContinue45
  %ifvar51 = load i32, i32* %ifvar, align 4
  %127 = add nsw i32 %ifvar51, 1
  store i32 %127, i32* %ifvar, align 4
  br label %bContinue50

bContinue50:                                      ; preds = %bTrue49, %bContinue45
  %128 = trunc i32 0 to i1
  br i1 %128, label %bTrue52, label %bContinue53

bTrue52:                                          ; preds = %bContinue50
  %ifvar54 = load i32, i32* %ifvar, align 4
  %129 = add nsw i32 %ifvar54, 1
  store i32 %129, i32* %ifvar, align 4
  br label %bContinue53

bContinue53:                                      ; preds = %bTrue52, %bContinue50
  %130 = trunc i32 1 to i1
  br i1 %130, label %bTrue55, label %bFalse

bTrue55:                                          ; preds = %bContinue53
  %ifvar57 = load i32, i32* %ifvar, align 4
  %131 = add nsw i32 %ifvar57, 10
  store i32 %131, i32* %ifvar, align 4
  br label %bContinue56

bFalse:                                           ; preds = %bContinue53
  %ifvar58 = load i32, i32* %ifvar, align 4
  %132 = add nsw i32 %ifvar58, 20
  store i32 %132, i32* %ifvar, align 4
  br label %bContinue56

bContinue56:                                      ; preds = %bFalse, %bTrue55
  %133 = trunc i32 0 to i1
  br i1 %133, label %bTrue59, label %bFalse60

bTrue59:                                          ; preds = %bContinue56
  %ifvar62 = load i32, i32* %ifvar, align 4
  %134 = add nsw i32 %ifvar62, 100
  store i32 %134, i32* %ifvar, align 4
  br label %bContinue61

bFalse60:                                         ; preds = %bContinue56
  %ifvar63 = load i32, i32* %ifvar, align 4
  %135 = add nsw i32 %ifvar63, 200
  store i32 %135, i32* %ifvar, align 4
  br label %bContinue61

bContinue61:                                      ; preds = %bFalse60, %bTrue59
  %ifvar66 = load i32, i32* %ifvar, align 4
  %136 = icmp eq i32 %ifvar66, 211
  %137 = zext i1 %136 to i32
  %138 = trunc i32 %137 to i1
  %139 = xor i1 %138, true
  %140 = zext i1 %139 to i32
  %141 = trunc i32 %140 to i1
  br i1 %141, label %bTrue64, label %bContinue65

bTrue64:                                          ; preds = %bContinue61
  %142 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @11, i32 0, i32 0))
  br label %bContinue65

bContinue65:                                      ; preds = %bTrue64, %bContinue61
  %x = alloca i32, align 4
  %sign1 = alloca i32, align 4
  %sign2 = alloca i32, align 4
  %sign3 = alloca i32, align 4
  %143 = sub nsw i32 0, 1
  store i32 %143, i32* %x, align 4
  %x68 = load i32, i32* %x, align 4
  %144 = icmp slt i32 %x68, 0
  %145 = zext i1 %144 to i32
  %146 = trunc i32 %145 to i1
  br i1 %146, label %SelectPt0, label %FSelectPt0

SelectPt0:                                        ; preds = %bContinue65
  %147 = sub nsw i32 0, 1
  store i32 %147, i32* %sign1, align 4
  br label %bContinue67

FSelectPt0:                                       ; preds = %bContinue65
  %x69 = load i32, i32* %x, align 4
  %148 = icmp eq i32 %x69, 0
  %149 = zext i1 %148 to i32
  %150 = trunc i32 %149 to i1
  br i1 %150, label %SelectPt1, label %FSelectPt1

SelectPt1:                                        ; preds = %FSelectPt0
  store i32 0, i32* %sign1, align 4
  br label %bContinue67

FSelectPt1:                                       ; preds = %FSelectPt0
  %x70 = load i32, i32* %x, align 4
  %151 = icmp sgt i32 %x70, 0
  %152 = zext i1 %151 to i32
  %153 = trunc i32 %152 to i1
  br i1 %153, label %SelectPt2, label %FSelectPt2

SelectPt2:                                        ; preds = %FSelectPt1
  store i32 7, i32* %sign1, align 4
  br label %bContinue67

FSelectPt2:                                       ; preds = %FSelectPt1
  br label %bContinue67

bContinue67:                                      ; preds = %FSelectPt2, %SelectPt2, %SelectPt1, %SelectPt0
  store i32 0, i32* %x, align 4
  %x78 = load i32, i32* %x, align 4
  %154 = icmp slt i32 %x78, 0
  %155 = zext i1 %154 to i32
  %156 = trunc i32 %155 to i1
  br i1 %156, label %SelectPt071, label %FSelectPt072

SelectPt071:                                      ; preds = %bContinue67
  %157 = sub nsw i32 0, 1
  store i32 %157, i32* %sign2, align 4
  br label %bContinue77

FSelectPt072:                                     ; preds = %bContinue67
  %x79 = load i32, i32* %x, align 4
  %158 = icmp eq i32 %x79, 0
  %159 = zext i1 %158 to i32
  %160 = trunc i32 %159 to i1
  br i1 %160, label %SelectPt173, label %FSelectPt174

SelectPt173:                                      ; preds = %FSelectPt072
  store i32 0, i32* %sign2, align 4
  br label %bContinue77

FSelectPt174:                                     ; preds = %FSelectPt072
  %x80 = load i32, i32* %x, align 4
  %161 = icmp sgt i32 %x80, 0
  %162 = zext i1 %161 to i32
  %163 = trunc i32 %162 to i1
  br i1 %163, label %SelectPt275, label %FSelectPt276

SelectPt275:                                      ; preds = %FSelectPt174
  store i32 1, i32* %sign2, align 4
  br label %bContinue77

FSelectPt276:                                     ; preds = %FSelectPt174
  br label %bContinue77

bContinue77:                                      ; preds = %FSelectPt276, %SelectPt275, %SelectPt173, %SelectPt071
  store i32 10, i32* %x, align 4
  %x88 = load i32, i32* %x, align 4
  %164 = icmp slt i32 %x88, 0
  %165 = zext i1 %164 to i32
  %166 = trunc i32 %165 to i1
  br i1 %166, label %SelectPt081, label %FSelectPt082

SelectPt081:                                      ; preds = %bContinue77
  %167 = sub nsw i32 0, 1
  store i32 %167, i32* %sign3, align 4
  br label %bContinue87

FSelectPt082:                                     ; preds = %bContinue77
  %x89 = load i32, i32* %x, align 4
  %168 = icmp eq i32 %x89, 0
  %169 = zext i1 %168 to i32
  %170 = trunc i32 %169 to i1
  br i1 %170, label %SelectPt183, label %FSelectPt184

SelectPt183:                                      ; preds = %FSelectPt082
  store i32 0, i32* %sign3, align 4
  br label %bContinue87

FSelectPt184:                                     ; preds = %FSelectPt082
  %x90 = load i32, i32* %x, align 4
  %171 = icmp sgt i32 %x90, 0
  %172 = zext i1 %171 to i32
  %173 = trunc i32 %172 to i1
  br i1 %173, label %SelectPt285, label %FSelectPt286

SelectPt285:                                      ; preds = %FSelectPt184
  store i32 1, i32* %sign3, align 4
  br label %bContinue87

FSelectPt286:                                     ; preds = %FSelectPt184
  br label %bContinue87

bContinue87:                                      ; preds = %FSelectPt286, %SelectPt285, %SelectPt183, %SelectPt081
  %sign193 = load i32, i32* %sign1, align 4
  %174 = sub nsw i32 0, 1
  %175 = icmp eq i32 %sign193, %174
  %176 = zext i1 %175 to i32
  %sign294 = load i32, i32* %sign2, align 4
  %177 = icmp eq i32 %sign294, 0
  %178 = zext i1 %177 to i32
  %179 = trunc i32 %176 to i1
  %180 = trunc i32 %178 to i1
  %181 = and i1 %179, %180
  %182 = zext i1 %181 to i32
  %sign395 = load i32, i32* %sign3, align 4
  %183 = icmp eq i32 %sign395, 1
  %184 = zext i1 %183 to i32
  %185 = trunc i32 %182 to i1
  %186 = trunc i32 %184 to i1
  %187 = and i1 %185, %186
  %188 = zext i1 %187 to i32
  %189 = trunc i32 %188 to i1
  %190 = xor i1 %189, true
  %191 = zext i1 %190 to i32
  %192 = trunc i32 %191 to i1
  br i1 %192, label %bTrue91, label %bContinue92

bTrue91:                                          ; preds = %bContinue87
  %193 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @12, i32 0, i32 0))
  br label %bContinue92

bContinue92:                                      ; preds = %bTrue91, %bContinue87
  %f1 = alloca i32, align 4
  %194 = call i32 @intf()
  store i32 %194, i32* %f1, align 4
  %f2 = alloca i32, align 4
  %anInt96 = load i32, i32* %anInt, align 4
  %195 = call i8* @strf()
  %196 = call i32 @boolf(i32 %anInt96, i32 1, i8* %195)
  store i32 %196, i32* %f2, align 4
  %s = alloca i8*, align 8
  %197 = call i8* @strf()
  store i8* %197, i8** %s, align 8
  %f199 = load i32, i32* %f1, align 4
  %198 = icmp eq i32 %f199, 3
  %199 = zext i1 %198 to i32
  %f2100 = load i32, i32* %f2, align 4
  %200 = trunc i32 %199 to i1
  %201 = trunc i32 %f2100 to i1
  %202 = and i1 %200, %201
  %203 = zext i1 %202 to i32
  %204 = trunc i32 %203 to i1
  %205 = xor i1 %204, true
  %206 = zext i1 %205 to i32
  %207 = trunc i32 %206 to i1
  br i1 %207, label %bTrue97, label %bContinue98

bTrue97:                                          ; preds = %bContinue92
  %208 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([10 x i8], [10 x i8]* @13, i32 0, i32 0))
  br label %bContinue98

bContinue98:                                      ; preds = %bTrue97, %bContinue92
  %globalVar = load i32, i32* @globalVar, align 4
  %209 = icmp eq i32 %globalVar, 5
  %210 = zext i1 %209 to i32
  %211 = trunc i32 %210 to i1
  %212 = xor i1 %211, true
  %213 = zext i1 %212 to i32
  %214 = trunc i32 %213 to i1
  br i1 %214, label %bTrue101, label %bContinue102

bTrue101:                                         ; preds = %bContinue98
  %globalVar103 = load i32, i32* @globalVar, align 4
  %215 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @14, i32 0, i32 0), i32 %globalVar103)
  br label %bContinue102

bContinue102:                                     ; preds = %bTrue101, %bContinue98
  %anInt104 = load i32, i32* %anInt, align 4
  call void @testProc(i32 %anInt104, i32 1, i8* getelementptr inbounds ([5 x i8], [5 x i8]* @15, i32 0, i32 0))
  %globalVar107 = load i32, i32* @globalVar, align 4
  %216 = icmp eq i32 %globalVar107, 3
  %217 = zext i1 %216 to i32
  %218 = trunc i32 %217 to i1
  %219 = xor i1 %218, true
  %220 = zext i1 %219 to i32
  %221 = trunc i32 %220 to i1
  br i1 %221, label %bTrue105, label %bContinue106

bTrue105:                                         ; preds = %bContinue102
  %222 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @16, i32 0, i32 0))
  br label %bContinue106

bContinue106:                                     ; preds = %bTrue105, %bContinue102
  call void @testProc2()
  %globalVar110 = load i32, i32* @globalVar, align 4
  %223 = icmp eq i32 %globalVar110, 320
  %224 = zext i1 %223 to i32
  %225 = trunc i32 %224 to i1
  %226 = xor i1 %225, true
  %227 = zext i1 %226 to i32
  %228 = trunc i32 %227 to i1
  br i1 %228, label %bTrue108, label %bContinue109

bTrue108:                                         ; preds = %bContinue106
  %globalVar111 = load i32, i32* @globalVar, align 4
  %229 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @17, i32 0, i32 0), i32 %globalVar111)
  br label %bContinue109

bContinue109:                                     ; preds = %bTrue108, %bContinue106
  %blockTest = alloca i32, align 4
  store i32 5, i32* %blockTest, align 4
  %blockTest112 = alloca i32, align 4
  store i32 7, i32* %blockTest112, align 4
  %blockTest115 = load i32, i32* %blockTest112, align 4
  %230 = icmp eq i32 %blockTest115, 7
  %231 = zext i1 %230 to i32
  %232 = trunc i32 %231 to i1
  %233 = xor i1 %232, true
  %234 = zext i1 %233 to i32
  %235 = trunc i32 %234 to i1
  br i1 %235, label %bTrue113, label %bContinue114

bTrue113:                                         ; preds = %bContinue109
  %236 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @18, i32 0, i32 0))
  br label %bContinue114

bContinue114:                                     ; preds = %bTrue113, %bContinue109
  %blockTest118 = load i32, i32* %blockTest, align 4
  %237 = icmp eq i32 %blockTest118, 5
  %238 = zext i1 %237 to i32
  %239 = trunc i32 %238 to i1
  %240 = xor i1 %239, true
  %241 = zext i1 %240 to i32
  %242 = trunc i32 %241 to i1
  br i1 %242, label %bTrue116, label %bContinue117

bTrue116:                                         ; preds = %bContinue114
  %blockTest119 = load i32, i32* %blockTest, align 4
  %243 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @19, i32 0, i32 0), i32 %blockTest119)
  br label %bContinue117

bContinue117:                                     ; preds = %bTrue116, %bContinue114
  %244 = icmp ne i32 1, 1
  %245 = zext i1 %244 to i32
  %246 = trunc i32 %245 to i1
  br i1 %246, label %bTrue120, label %bContinue121

bTrue120:                                         ; preds = %bContinue117
  %247 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @20, i32 0, i32 0))
  br label %bContinue121

bContinue121:                                     ; preds = %bTrue120, %bContinue117
  %248 = icmp ne i32 1, 2
  %249 = zext i1 %248 to i32
  %250 = trunc i32 %249 to i1
  %251 = xor i1 %250, true
  %252 = zext i1 %251 to i32
  %253 = trunc i32 %252 to i1
  br i1 %253, label %bTrue122, label %bContinue123

bTrue122:                                         ; preds = %bContinue121
  %254 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @21, i32 0, i32 0))
  br label %bContinue123

bContinue123:                                     ; preds = %bTrue122, %bContinue121
  %255 = trunc i32 1 to i1
  %256 = xor i1 %255, true
  %257 = zext i1 %256 to i32
  %258 = trunc i32 %257 to i1
  br i1 %258, label %bTrue124, label %bContinue125

bTrue124:                                         ; preds = %bContinue123
  %259 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @22, i32 0, i32 0))
  br label %bContinue125

bContinue125:                                     ; preds = %bTrue124, %bContinue123
  %260 = trunc i32 0 to i1
  %261 = xor i1 %260, true
  %262 = zext i1 %261 to i32
  %263 = trunc i32 %262 to i1
  %264 = xor i1 %263, true
  %265 = zext i1 %264 to i32
  %266 = trunc i32 %265 to i1
  br i1 %266, label %bTrue126, label %bContinue127

bTrue126:                                         ; preds = %bContinue125
  %267 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @23, i32 0, i32 0))
  br label %bContinue127

bContinue127:                                     ; preds = %bTrue126, %bContinue125
  %268 = icmp eq i32 1, 2
  %269 = zext i1 %268 to i32
  %270 = trunc i32 %269 to i1
  br i1 %270, label %bTrue128, label %bContinue129

bTrue128:                                         ; preds = %bContinue127
  %271 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @24, i32 0, i32 0))
  br label %bContinue129

bContinue129:                                     ; preds = %bTrue128, %bContinue127
  %272 = icmp eq i32 1, 1
  %273 = zext i1 %272 to i32
  %274 = trunc i32 %273 to i1
  %275 = xor i1 %274, true
  %276 = zext i1 %275 to i32
  %277 = trunc i32 %276 to i1
  br i1 %277, label %bTrue130, label %bContinue131

bTrue130:                                         ; preds = %bContinue129
  %278 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @25, i32 0, i32 0))
  br label %bContinue131

bContinue131:                                     ; preds = %bTrue130, %bContinue129
  %279 = icmp sgt i32 1, 1
  %280 = zext i1 %279 to i32
  %281 = trunc i32 %280 to i1
  br i1 %281, label %bTrue132, label %bContinue133

bTrue132:                                         ; preds = %bContinue131
  %282 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @26, i32 0, i32 0))
  br label %bContinue133

bContinue133:                                     ; preds = %bTrue132, %bContinue131
  %283 = icmp sgt i32 1, 0
  %284 = zext i1 %283 to i32
  %285 = trunc i32 %284 to i1
  %286 = xor i1 %285, true
  %287 = zext i1 %286 to i32
  %288 = trunc i32 %287 to i1
  br i1 %288, label %bTrue134, label %bContinue135

bTrue134:                                         ; preds = %bContinue133
  %289 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @27, i32 0, i32 0))
  br label %bContinue135

bContinue135:                                     ; preds = %bTrue134, %bContinue133
  %290 = icmp slt i32 1, 1
  %291 = zext i1 %290 to i32
  %292 = trunc i32 %291 to i1
  br i1 %292, label %bTrue136, label %bContinue137

bTrue136:                                         ; preds = %bContinue135
  %293 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @28, i32 0, i32 0))
  br label %bContinue137

bContinue137:                                     ; preds = %bTrue136, %bContinue135
  %294 = icmp slt i32 1, 2
  %295 = zext i1 %294 to i32
  %296 = trunc i32 %295 to i1
  %297 = xor i1 %296, true
  %298 = zext i1 %297 to i32
  %299 = trunc i32 %298 to i1
  br i1 %299, label %bTrue138, label %bContinue139

bTrue138:                                         ; preds = %bContinue137
  %300 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @29, i32 0, i32 0))
  br label %bContinue139

bContinue139:                                     ; preds = %bTrue138, %bContinue137
  %301 = icmp sge i32 1, 2
  %302 = zext i1 %301 to i32
  %303 = trunc i32 %302 to i1
  br i1 %303, label %bTrue140, label %bContinue141

bTrue140:                                         ; preds = %bContinue139
  %304 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @30, i32 0, i32 0))
  br label %bContinue141

bContinue141:                                     ; preds = %bTrue140, %bContinue139
  %305 = icmp sge i32 1, 1
  %306 = zext i1 %305 to i32
  %307 = trunc i32 %306 to i1
  %308 = xor i1 %307, true
  %309 = zext i1 %308 to i32
  %310 = trunc i32 %309 to i1
  br i1 %310, label %bTrue142, label %bContinue143

bTrue142:                                         ; preds = %bContinue141
  %311 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @31, i32 0, i32 0))
  br label %bContinue143

bContinue143:                                     ; preds = %bTrue142, %bContinue141
  %312 = icmp sle i32 1, 0
  %313 = zext i1 %312 to i32
  %314 = trunc i32 %313 to i1
  br i1 %314, label %bTrue144, label %bContinue145

bTrue144:                                         ; preds = %bContinue143
  %315 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @32, i32 0, i32 0))
  br label %bContinue145

bContinue145:                                     ; preds = %bTrue144, %bContinue143
  %316 = icmp sle i32 1, 1
  %317 = zext i1 %316 to i32
  %318 = trunc i32 %317 to i1
  %319 = xor i1 %318, true
  %320 = zext i1 %319 to i32
  %321 = trunc i32 %320 to i1
  br i1 %321, label %bTrue146, label %bContinue147

bTrue146:                                         ; preds = %bContinue145
  %322 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @33, i32 0, i32 0))
  br label %bContinue147

bContinue147:                                     ; preds = %bTrue146, %bContinue145
  %323 = trunc i32 1 to i1
  %324 = trunc i32 1 to i1
  %325 = and i1 %323, %324
  %326 = zext i1 %325 to i32
  %327 = trunc i32 %326 to i1
  %328 = xor i1 %327, true
  %329 = zext i1 %328 to i32
  %330 = trunc i32 %329 to i1
  br i1 %330, label %bTrue148, label %bContinue149

bTrue148:                                         ; preds = %bContinue147
  %331 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @34, i32 0, i32 0))
  br label %bContinue149

bContinue149:                                     ; preds = %bTrue148, %bContinue147
  %332 = trunc i32 1 to i1
  %333 = trunc i32 0 to i1
  %334 = and i1 %332, %333
  %335 = zext i1 %334 to i32
  %336 = trunc i32 %335 to i1
  br i1 %336, label %bTrue150, label %bContinue151

bTrue150:                                         ; preds = %bContinue149
  %337 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @35, i32 0, i32 0))
  br label %bContinue151

bContinue151:                                     ; preds = %bTrue150, %bContinue149
  %338 = trunc i32 0 to i1
  %339 = trunc i32 1 to i1
  %340 = and i1 %338, %339
  %341 = zext i1 %340 to i32
  %342 = trunc i32 %341 to i1
  br i1 %342, label %bTrue152, label %bContinue153

bTrue152:                                         ; preds = %bContinue151
  %343 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @36, i32 0, i32 0))
  br label %bContinue153

bContinue153:                                     ; preds = %bTrue152, %bContinue151
  %344 = trunc i32 0 to i1
  %345 = trunc i32 0 to i1
  %346 = and i1 %344, %345
  %347 = zext i1 %346 to i32
  %348 = trunc i32 %347 to i1
  br i1 %348, label %bTrue154, label %bContinue155

bTrue154:                                         ; preds = %bContinue153
  %349 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @37, i32 0, i32 0))
  br label %bContinue155

bContinue155:                                     ; preds = %bTrue154, %bContinue153
  %350 = trunc i32 1 to i1
  %351 = trunc i32 1 to i1
  %352 = or i1 %350, %351
  %353 = zext i1 %352 to i32
  %354 = trunc i32 %353 to i1
  %355 = xor i1 %354, true
  %356 = zext i1 %355 to i32
  %357 = trunc i32 %356 to i1
  br i1 %357, label %bTrue156, label %bContinue157

bTrue156:                                         ; preds = %bContinue155
  %358 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @38, i32 0, i32 0))
  br label %bContinue157

bContinue157:                                     ; preds = %bTrue156, %bContinue155
  %359 = trunc i32 1 to i1
  %360 = trunc i32 0 to i1
  %361 = or i1 %359, %360
  %362 = zext i1 %361 to i32
  %363 = trunc i32 %362 to i1
  %364 = xor i1 %363, true
  %365 = zext i1 %364 to i32
  %366 = trunc i32 %365 to i1
  br i1 %366, label %bTrue158, label %bContinue159

bTrue158:                                         ; preds = %bContinue157
  %367 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @39, i32 0, i32 0))
  br label %bContinue159

bContinue159:                                     ; preds = %bTrue158, %bContinue157
  %368 = trunc i32 0 to i1
  %369 = trunc i32 1 to i1
  %370 = or i1 %368, %369
  %371 = zext i1 %370 to i32
  %372 = trunc i32 %371 to i1
  %373 = xor i1 %372, true
  %374 = zext i1 %373 to i32
  %375 = trunc i32 %374 to i1
  br i1 %375, label %bTrue160, label %bContinue161

bTrue160:                                         ; preds = %bContinue159
  %376 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @40, i32 0, i32 0))
  br label %bContinue161

bContinue161:                                     ; preds = %bTrue160, %bContinue159
  %377 = trunc i32 0 to i1
  %378 = trunc i32 0 to i1
  %379 = or i1 %377, %378
  %380 = zext i1 %379 to i32
  %381 = trunc i32 %380 to i1
  br i1 %381, label %bTrue162, label %bContinue163

bTrue162:                                         ; preds = %bContinue161
  %382 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @41, i32 0, i32 0))
  br label %bContinue163

bContinue163:                                     ; preds = %bTrue162, %bContinue161
  %383 = trunc i32 0 to i1
  %384 = trunc i32 0 to i1
  %385 = and i1 %383, %384
  %386 = zext i1 %385 to i32
  %387 = trunc i32 1 to i1
  %388 = trunc i32 %386 to i1
  %389 = or i1 %387, %388
  %390 = zext i1 %389 to i32
  %391 = trunc i32 %390 to i1
  %392 = xor i1 %391, true
  %393 = zext i1 %392 to i32
  %394 = trunc i32 %393 to i1
  br i1 %394, label %bTrue164, label %bContinue165

bTrue164:                                         ; preds = %bContinue163
  %395 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @42, i32 0, i32 0))
  br label %bContinue165

bContinue165:                                     ; preds = %bTrue164, %bContinue163
  %396 = trunc i32 0 to i1
  %397 = trunc i32 0 to i1
  %398 = and i1 %396, %397
  %399 = zext i1 %398 to i32
  %400 = trunc i32 %399 to i1
  %401 = trunc i32 1 to i1
  %402 = or i1 %400, %401
  %403 = zext i1 %402 to i32
  %404 = trunc i32 %403 to i1
  %405 = xor i1 %404, true
  %406 = zext i1 %405 to i32
  %407 = trunc i32 %406 to i1
  br i1 %407, label %bTrue166, label %bContinue167

bTrue166:                                         ; preds = %bContinue165
  %408 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @43, i32 0, i32 0))
  br label %bContinue167

bContinue167:                                     ; preds = %bTrue166, %bContinue165
  %409 = trunc i32 0 to i1
  %410 = trunc i32 1 to i1
  %411 = or i1 %409, %410
  %412 = zext i1 %411 to i32
  %413 = trunc i32 0 to i1
  %414 = trunc i32 %412 to i1
  %415 = and i1 %413, %414
  %416 = zext i1 %415 to i32
  %417 = trunc i32 %416 to i1
  br i1 %417, label %bTrue168, label %bContinue169

bTrue168:                                         ; preds = %bContinue167
  %418 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @44, i32 0, i32 0))
  br label %bContinue169

bContinue169:                                     ; preds = %bTrue168, %bContinue167
  %419 = mul nsw i32 3, 7
  %420 = add nsw i32 2, %419
  %421 = icmp ne i32 %420, 23
  %422 = zext i1 %421 to i32
  %423 = trunc i32 %422 to i1
  br i1 %423, label %bTrue170, label %bContinue171

bTrue170:                                         ; preds = %bContinue169
  %424 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @45, i32 0, i32 0))
  br label %bContinue171

bContinue171:                                     ; preds = %bTrue170, %bContinue169
  %425 = add nsw i32 2, 3
  %426 = mul nsw i32 %425, 7
  %427 = icmp ne i32 %426, 35
  %428 = zext i1 %427 to i32
  %429 = trunc i32 %428 to i1
  br i1 %429, label %bTrue172, label %bContinue173

bTrue172:                                         ; preds = %bContinue171
  %430 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @46, i32 0, i32 0))
  br label %bContinue173

bContinue173:                                     ; preds = %bTrue172, %bContinue171
  %431 = mul nsw i32 2, 3
  %432 = add nsw i32 %431, 7
  %433 = icmp ne i32 %432, 13
  %434 = zext i1 %433 to i32
  %435 = trunc i32 %434 to i1
  br i1 %435, label %bTrue174, label %bContinue175

bTrue174:                                         ; preds = %bContinue173
  %436 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([11 x i8], [11 x i8]* @47, i32 0, i32 0))
  br label %bContinue175

bContinue175:                                     ; preds = %bTrue174, %bContinue173
  %437 = add nsw i32 3, 7
  %438 = mul nsw i32 2, %437
  %439 = icmp ne i32 %438, 20
  %440 = zext i1 %439 to i32
  %441 = trunc i32 %440 to i1
  br i1 %441, label %bTrue176, label %bContinue177

bTrue176:                                         ; preds = %bContinue175
  %442 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([13 x i8], [13 x i8]* @48, i32 0, i32 0))
  br label %bContinue177

bContinue177:                                     ; preds = %bTrue176, %bContinue175
  %443 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 2
  %444 = load i32, i32* %443, align 4
  store i32 %444, i32* %x, align 4
  %445 = add nsw i32 2, 1
  %446 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 %445
  %447 = load i32, i32* %446, align 4
  %448 = icmp eq i32 %447, 3
  %449 = zext i1 %448 to i32
  %450 = trunc i32 %449 to i1
  br i1 %450, label %bTrue178, label %bContinue179

bTrue178:                                         ; preds = %bContinue177
  %451 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([12 x i8], [12 x i8]* @49, i32 0, i32 0))
  br label %bContinue179

bContinue179:                                     ; preds = %bTrue178, %bContinue177
  store i32 3, i32* %x, align 4
  %x180 = load i32, i32* %x, align 4
  %452 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 %x180
  %453 = load i32, i32* %452, align 4
  store i32 3, i32* %452, align 4
  %454 = getelementptr [5 x i32], [5 x i32]* %arr, i32 0, i32 3
  %455 = load i32, i32* %454, align 4
  %456 = icmp eq i32 %455, 3
  %457 = zext i1 %456 to i32
  %458 = trunc i32 %457 to i1
  %459 = xor i1 %458, true
  %460 = zext i1 %459 to i32
  %461 = trunc i32 %460 to i1
  br i1 %461, label %bTrue181, label %bContinue182

bTrue181:                                         ; preds = %bContinue179
  %462 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([16 x i8], [16 x i8]* @50, i32 0, i32 0))
  br label %bContinue182

bContinue182:                                     ; preds = %bTrue181, %bContinue179
  %463 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([6 x i8], [6 x i8]* @51, i32 0, i32 0))
  ret i32 5
}
