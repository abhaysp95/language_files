
debug/stack_vs_heap:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
_init():
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    rsp,0x8
    1008:	48 8b 05 d9 2f 00 00 	mov    rax,QWORD PTR [rip+0x2fd9]        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   rax,rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   rax
    1016:	48 83 c4 08          	add    rsp,0x8
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 2f 00 00    	push   QWORD PTR [rip+0x2fe2]        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmp    QWORD PTR [rip+0x2fe4]        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

0000000000001030 <operator new[](unsigned long)@plt>:
    1030:	ff 25 e2 2f 00 00    	jmp    QWORD PTR [rip+0x2fe2]        # 4018 <operator new[](unsigned long)@GLIBCXX_3.4>
    1036:	68 00 00 00 00       	push   0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <.plt>

0000000000001040 <__cxa_atexit@plt>:
    1040:	ff 25 da 2f 00 00    	jmp    QWORD PTR [rip+0x2fda]        # 4020 <__cxa_atexit@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <.plt>

0000000000001050 <operator delete(void*)@plt>:
    1050:	ff 25 d2 2f 00 00    	jmp    QWORD PTR [rip+0x2fd2]        # 4028 <operator delete(void*)@GLIBCXX_3.4>
    1056:	68 02 00 00 00       	push   0x2
    105b:	e9 c0 ff ff ff       	jmp    1020 <.plt>

0000000000001060 <operator new(unsigned long)@plt>:
    1060:	ff 25 ca 2f 00 00    	jmp    QWORD PTR [rip+0x2fca]        # 4030 <operator new(unsigned long)@GLIBCXX_3.4>
    1066:	68 03 00 00 00       	push   0x3
    106b:	e9 b0 ff ff ff       	jmp    1020 <.plt>

0000000000001070 <__stack_chk_fail@plt>:
    1070:	ff 25 c2 2f 00 00    	jmp    QWORD PTR [rip+0x2fc2]        # 4038 <__stack_chk_fail@GLIBC_2.4>
    1076:	68 04 00 00 00       	push   0x4
    107b:	e9 a0 ff ff ff       	jmp    1020 <.plt>

0000000000001080 <operator delete[](void*)@plt>:
    1080:	ff 25 ba 2f 00 00    	jmp    QWORD PTR [rip+0x2fba]        # 4040 <operator delete[](void*)@GLIBCXX_3.4>
    1086:	68 05 00 00 00       	push   0x5
    108b:	e9 90 ff ff ff       	jmp    1020 <.plt>

0000000000001090 <std::ios_base::Init::Init()@plt>:
    1090:	ff 25 b2 2f 00 00    	jmp    QWORD PTR [rip+0x2fb2]        # 4048 <std::ios_base::Init::Init()@GLIBCXX_3.4>
    1096:	68 06 00 00 00       	push   0x6
    109b:	e9 80 ff ff ff       	jmp    1020 <.plt>

00000000000010a0 <_Unwind_Resume@plt>:
    10a0:	ff 25 aa 2f 00 00    	jmp    QWORD PTR [rip+0x2faa]        # 4050 <_Unwind_Resume@GCC_3.0>
    10a6:	68 07 00 00 00       	push   0x7
    10ab:	e9 70 ff ff ff       	jmp    1020 <.plt>

Disassembly of section .text:

00000000000010b0 <__cxx_global_var_init>:
__cxx_global_var_init():
/usr/bin/../lib64/gcc/x86_64-pc-linux-gnu/10.2.0/../../../../include/c++/10.2.0/iostream:74
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
    10b0:	55                   	push   rbp
    10b1:	48 89 e5             	mov    rbp,rsp
    10b4:	48 8d 3d b6 2f 00 00 	lea    rdi,[rip+0x2fb6]        # 4071 <std::__ioinit>
    10bb:	e8 d0 ff ff ff       	call   1090 <std::ios_base::Init::Init()@plt>
    10c0:	48 8b 05 31 2f 00 00 	mov    rax,QWORD PTR [rip+0x2f31]        # 3ff8 <std::ios_base::Init::~Init()@GLIBCXX_3.4>
    10c7:	48 89 c7             	mov    rdi,rax
    10ca:	48 8d 35 a0 2f 00 00 	lea    rsi,[rip+0x2fa0]        # 4071 <std::__ioinit>
    10d1:	48 8d 15 88 2f 00 00 	lea    rdx,[rip+0x2f88]        # 4060 <__dso_handle>
    10d8:	e8 63 ff ff ff       	call   1040 <__cxa_atexit@plt>
    10dd:	5d                   	pop    rbp
    10de:	c3                   	ret    
    10df:	90                   	nop

00000000000010e0 <_GLOBAL__sub_I_main.cpp>:
_GLOBAL__sub_I_main.cpp():
    10e0:	55                   	push   rbp
    10e1:	48 89 e5             	mov    rbp,rsp
    10e4:	e8 c7 ff ff ff       	call   10b0 <__cxx_global_var_init>
    10e9:	5d                   	pop    rbp
    10ea:	c3                   	ret    
    10eb:	0f 1f 44 00 00       	nop    DWORD PTR [rax+rax*1+0x0]

00000000000010f0 <_start>:
_start():
    10f0:	f3 0f 1e fa          	endbr64 
    10f4:	31 ed                	xor    ebp,ebp
    10f6:	49 89 d1             	mov    r9,rdx
    10f9:	5e                   	pop    rsi
    10fa:	48 89 e2             	mov    rdx,rsp
    10fd:	48 83 e4 f0          	and    rsp,0xfffffffffffffff0
    1101:	50                   	push   rax
    1102:	54                   	push   rsp
    1103:	4c 8d 05 26 03 00 00 	lea    r8,[rip+0x326]        # 1430 <__libc_csu_fini>
    110a:	48 8d 0d af 02 00 00 	lea    rcx,[rip+0x2af]        # 13c0 <__libc_csu_init>
    1111:	48 8d 3d d8 00 00 00 	lea    rdi,[rip+0xd8]        # 11f0 <main>
    1118:	ff 15 c2 2e 00 00    	call   QWORD PTR [rip+0x2ec2]        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    111e:	f4                   	hlt    
    111f:	90                   	nop

0000000000001120 <deregister_tm_clones>:
deregister_tm_clones():
    1120:	48 8d 3d 49 2f 00 00 	lea    rdi,[rip+0x2f49]        # 4070 <__TMC_END__>
    1127:	48 8d 05 42 2f 00 00 	lea    rax,[rip+0x2f42]        # 4070 <__TMC_END__>
    112e:	48 39 f8             	cmp    rax,rdi
    1131:	74 15                	je     1148 <deregister_tm_clones+0x28>
    1133:	48 8b 05 9e 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e9e]        # 3fd8 <_ITM_deregisterTMCloneTable>
    113a:	48 85 c0             	test   rax,rax
    113d:	74 09                	je     1148 <deregister_tm_clones+0x28>
    113f:	ff e0                	jmp    rax
    1141:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1148:	c3                   	ret    
    1149:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001150 <register_tm_clones>:
register_tm_clones():
    1150:	48 8d 3d 19 2f 00 00 	lea    rdi,[rip+0x2f19]        # 4070 <__TMC_END__>
    1157:	48 8d 35 12 2f 00 00 	lea    rsi,[rip+0x2f12]        # 4070 <__TMC_END__>
    115e:	48 29 fe             	sub    rsi,rdi
    1161:	48 89 f0             	mov    rax,rsi
    1164:	48 c1 ee 3f          	shr    rsi,0x3f
    1168:	48 c1 f8 03          	sar    rax,0x3
    116c:	48 01 c6             	add    rsi,rax
    116f:	48 d1 fe             	sar    rsi,1
    1172:	74 14                	je     1188 <register_tm_clones+0x38>
    1174:	48 8b 05 75 2e 00 00 	mov    rax,QWORD PTR [rip+0x2e75]        # 3ff0 <_ITM_registerTMCloneTable>
    117b:	48 85 c0             	test   rax,rax
    117e:	74 08                	je     1188 <register_tm_clones+0x38>
    1180:	ff e0                	jmp    rax
    1182:	66 0f 1f 44 00 00    	nop    WORD PTR [rax+rax*1+0x0]
    1188:	c3                   	ret    
    1189:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

0000000000001190 <__do_global_dtors_aux>:
__do_global_dtors_aux():
    1190:	f3 0f 1e fa          	endbr64 
    1194:	80 3d d5 2e 00 00 00 	cmp    BYTE PTR [rip+0x2ed5],0x0        # 4070 <__TMC_END__>
    119b:	75 33                	jne    11d0 <__do_global_dtors_aux+0x40>
    119d:	55                   	push   rbp
    119e:	48 83 3d 2a 2e 00 00 00 	cmp    QWORD PTR [rip+0x2e2a],0x0        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    11a6:	48 89 e5             	mov    rbp,rsp
    11a9:	74 0d                	je     11b8 <__do_global_dtors_aux+0x28>
    11ab:	48 8b 3d ae 2e 00 00 	mov    rdi,QWORD PTR [rip+0x2eae]        # 4060 <__dso_handle>
    11b2:	ff 15 18 2e 00 00    	call   QWORD PTR [rip+0x2e18]        # 3fd0 <__cxa_finalize@GLIBC_2.2.5>
    11b8:	e8 63 ff ff ff       	call   1120 <deregister_tm_clones>
    11bd:	c6 05 ac 2e 00 00 01 	mov    BYTE PTR [rip+0x2eac],0x1        # 4070 <__TMC_END__>
    11c4:	5d                   	pop    rbp
    11c5:	c3                   	ret    
    11c6:	66 2e 0f 1f 84 00 00 00 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
    11d0:	c3                   	ret    
    11d1:	66 66 2e 0f 1f 84 00 00 00 00 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]
    11dc:	0f 1f 40 00          	nop    DWORD PTR [rax+0x0]

00000000000011e0 <frame_dummy>:
frame_dummy():
    11e0:	f3 0f 1e fa          	endbr64 
    11e4:	e9 67 ff ff ff       	jmp    1150 <register_tm_clones>
    11e9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]

00000000000011f0 <main>:
main():
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:10
struct demo_obj {
	float x, y, z;
	demo_obj(): x(10), y(20), z(30) {};
};

int main(int argc, char **argv) {
    11f0:	55                   	push   rbp
    11f1:	48 89 e5             	mov    rbp,rsp
    11f4:	48 81 ec a0 00 00 00 	sub    rsp,0xa0
    11fb:	64 48 8b 04 25 28 00 00 00 	mov    rax,QWORD PTR fs:0x28
    1204:	48 89 45 f8          	mov    QWORD PTR [rbp-0x8],rax
    1208:	c7 45 cc 00 00 00 00 	mov    DWORD PTR [rbp-0x34],0x0
    120f:	89 7d c8             	mov    DWORD PTR [rbp-0x38],edi
    1212:	48 89 75 c0          	mov    QWORD PTR [rbp-0x40],rsi
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:12
	/** stack */
	int value = 5;
    1216:	c7 45 bc 05 00 00 00 	mov    DWORD PTR [rbp-0x44],0x5
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:14
	int array[5];
	array[0] = 5;
    121d:	c7 45 e0 05 00 00 00 	mov    DWORD PTR [rbp-0x20],0x5
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:15
	array[1] = 4;
    1224:	c7 45 e4 04 00 00 00 	mov    DWORD PTR [rbp-0x1c],0x4
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:16
	array[2] = 3;
    122b:	c7 45 e8 03 00 00 00 	mov    DWORD PTR [rbp-0x18],0x3
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:17
	array[3] = 2;
    1232:	c7 45 ec 02 00 00 00 	mov    DWORD PTR [rbp-0x14],0x2
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:18
	array[4] = 1;
    1239:	c7 45 f0 01 00 00 00 	mov    DWORD PTR [rbp-0x10],0x1
    1240:	48 8d 7d d0          	lea    rdi,[rbp-0x30]
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:19
	demo_obj d1;
    1244:	e8 37 01 00 00       	call   1380 <demo_obj::demo_obj()>
    1249:	bf 04 00 00 00       	mov    edi,0x4
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:22

	/** heap */
	int* val = new int;
    124e:	e8 0d fe ff ff       	call   1060 <operator new(unsigned long)@plt>
    1253:	48 89 45 b0          	mov    QWORD PTR [rbp-0x50],rax
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:23
	*val = 5;
    1257:	48 8b 45 b0          	mov    rax,QWORD PTR [rbp-0x50]
    125b:	c7 00 05 00 00 00    	mov    DWORD PTR [rax],0x5
    1261:	bf 14 00 00 00       	mov    edi,0x14
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:24
	int* arr = new int[5];
    1266:	e8 c5 fd ff ff       	call   1030 <operator new[](unsigned long)@plt>
    126b:	48 89 45 a8          	mov    QWORD PTR [rbp-0x58],rax
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:25
	arr[0] = 5;
    126f:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    1273:	c7 00 05 00 00 00    	mov    DWORD PTR [rax],0x5
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:26
	arr[1] = 4;
    1279:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    127d:	c7 40 04 04 00 00 00 	mov    DWORD PTR [rax+0x4],0x4
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:27
	arr[2] = 3;
    1284:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    1288:	c7 40 08 03 00 00 00 	mov    DWORD PTR [rax+0x8],0x3
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:28
	arr[3] = 2;
    128f:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    1293:	c7 40 0c 02 00 00 00 	mov    DWORD PTR [rax+0xc],0x2
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:29
	arr[4] = 1;
    129a:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    129e:	c7 40 10 01 00 00 00 	mov    DWORD PTR [rax+0x10],0x1
    12a5:	bf 0c 00 00 00       	mov    edi,0xc
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:30
	demo_obj* d2 = new demo_obj();
    12aa:	e8 b1 fd ff ff       	call   1060 <operator new(unsigned long)@plt>
    12af:	48 89 c1             	mov    rcx,rax
    12b2:	48 89 c2             	mov    rdx,rax
    12b5:	48 89 c7             	mov    rdi,rax
    12b8:	48 89 4d 88          	mov    QWORD PTR [rbp-0x78],rcx
    12bc:	48 89 55 80          	mov    QWORD PTR [rbp-0x80],rdx
    12c0:	e8 bb 00 00 00       	call   1380 <demo_obj::demo_obj()>
    12c5:	e9 00 00 00 00       	jmp    12ca <main+0xda>
    12ca:	48 8b 45 80          	mov    rax,QWORD PTR [rbp-0x80]
    12ce:	48 89 45 a0          	mov    QWORD PTR [rbp-0x60],rax
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:31
	delete val;
    12d2:	48 8b 4d b0          	mov    rcx,QWORD PTR [rbp-0x50]
    12d6:	48 83 f9 00          	cmp    rcx,0x0
    12da:	48 89 8d 78 ff ff ff 	mov    QWORD PTR [rbp-0x88],rcx
    12e1:	0f 84 0f 00 00 00    	je     12f6 <main+0x106>
    12e7:	48 8b 85 78 ff ff ff 	mov    rax,QWORD PTR [rbp-0x88]
    12ee:	48 89 c7             	mov    rdi,rax
    12f1:	e8 5a fd ff ff       	call   1050 <operator delete(void*)@plt>
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:32
	delete[] arr;
    12f6:	48 8b 45 a8          	mov    rax,QWORD PTR [rbp-0x58]
    12fa:	48 83 f8 00          	cmp    rax,0x0
    12fe:	48 89 85 70 ff ff ff 	mov    QWORD PTR [rbp-0x90],rax
    1305:	0f 84 0f 00 00 00    	je     131a <main+0x12a>
    130b:	48 8b 85 70 ff ff ff 	mov    rax,QWORD PTR [rbp-0x90]
    1312:	48 89 c7             	mov    rdi,rax
    1315:	e8 66 fd ff ff       	call   1080 <operator delete[](void*)@plt>
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:33
	delete d2;
    131a:	48 8b 45 a0          	mov    rax,QWORD PTR [rbp-0x60]
    131e:	48 83 f8 00          	cmp    rax,0x0
    1322:	48 89 85 68 ff ff ff 	mov    QWORD PTR [rbp-0x98],rax
    1329:	0f 84 0f 00 00 00    	je     133e <main+0x14e>
    132f:	48 8b 85 68 ff ff ff 	mov    rax,QWORD PTR [rbp-0x98]
    1336:	48 89 c7             	mov    rdi,rax
    1339:	e8 12 fd ff ff       	call   1050 <operator delete(void*)@plt>
    133e:	64 48 8b 04 25 28 00 00 00 	mov    rax,QWORD PTR fs:0x28
    1347:	48 8b 4d f8          	mov    rcx,QWORD PTR [rbp-0x8]
    134b:	48 39 c8             	cmp    rax,rcx
    134e:	0f 85 24 00 00 00    	jne    1378 <main+0x188>
    1354:	31 c0                	xor    eax,eax
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:34
	return 0;
    1356:	48 81 c4 a0 00 00 00 	add    rsp,0xa0
    135d:	5d                   	pop    rbp
    135e:	c3                   	ret    
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:35
    135f:	48 89 45 98          	mov    QWORD PTR [rbp-0x68],rax
    1363:	89 55 94             	mov    DWORD PTR [rbp-0x6c],edx
    1366:	48 8b 7d 88          	mov    rdi,QWORD PTR [rbp-0x78]
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:30
	demo_obj* d2 = new demo_obj();
    136a:	e8 e1 fc ff ff       	call   1050 <operator delete(void*)@plt>
    136f:	48 8b 7d 98          	mov    rdi,QWORD PTR [rbp-0x68]
    1373:	e8 28 fd ff ff       	call   10a0 <_Unwind_Resume@plt>
    1378:	e8 f3 fc ff ff       	call   1070 <__stack_chk_fail@plt>
    137d:	0f 1f 00             	nop    DWORD PTR [rax]

0000000000001380 <demo_obj::demo_obj()>:
demo_obj():
/home/raytracer/Documents/ncpp/practice/the_cherno/stack_vs_heap/src/main.cpp:7
	demo_obj(): x(10), y(20), z(30) {};
    1380:	55                   	push   rbp
    1381:	48 89 e5             	mov    rbp,rsp
    1384:	f3 0f 10 05 78 0c 00 00 	movss  xmm0,DWORD PTR [rip+0xc78]        # 2004 <_IO_stdin_used+0x4>
    138c:	f3 0f 10 0d 74 0c 00 00 	movss  xmm1,DWORD PTR [rip+0xc74]        # 2008 <_IO_stdin_used+0x8>
    1394:	f3 0f 10 15 70 0c 00 00 	movss  xmm2,DWORD PTR [rip+0xc70]        # 200c <_IO_stdin_used+0xc>
    139c:	48 89 7d f8          	mov    QWORD PTR [rbp-0x8],rdi
    13a0:	48 8b 45 f8          	mov    rax,QWORD PTR [rbp-0x8]
    13a4:	f3 0f 11 10          	movss  DWORD PTR [rax],xmm2
    13a8:	f3 0f 11 48 04       	movss  DWORD PTR [rax+0x4],xmm1
    13ad:	f3 0f 11 40 08       	movss  DWORD PTR [rax+0x8],xmm0
    13b2:	5d                   	pop    rbp
    13b3:	c3                   	ret    
demo_obj::demo_obj():
    13b4:	66 2e 0f 1f 84 00 00 00 00 00 	nop    WORD PTR cs:[rax+rax*1+0x0]
    13be:	66 90                	xchg   ax,ax

00000000000013c0 <__libc_csu_init>:
__libc_csu_init():
    13c0:	f3 0f 1e fa          	endbr64 
    13c4:	41 57                	push   r15
    13c6:	4c 8d 3d cb 29 00 00 	lea    r15,[rip+0x29cb]        # 3d98 <__frame_dummy_init_array_entry>
    13cd:	41 56                	push   r14
    13cf:	49 89 d6             	mov    r14,rdx
    13d2:	41 55                	push   r13
    13d4:	49 89 f5             	mov    r13,rsi
    13d7:	41 54                	push   r12
    13d9:	41 89 fc             	mov    r12d,edi
    13dc:	55                   	push   rbp
    13dd:	48 8d 2d c4 29 00 00 	lea    rbp,[rip+0x29c4]        # 3da8 <__do_global_dtors_aux_fini_array_entry>
    13e4:	53                   	push   rbx
    13e5:	4c 29 fd             	sub    rbp,r15
    13e8:	48 83 ec 08          	sub    rsp,0x8
    13ec:	e8 0f fc ff ff       	call   1000 <_init>
    13f1:	48 c1 fd 03          	sar    rbp,0x3
    13f5:	74 1f                	je     1416 <__libc_csu_init+0x56>
    13f7:	31 db                	xor    ebx,ebx
    13f9:	0f 1f 80 00 00 00 00 	nop    DWORD PTR [rax+0x0]
    1400:	4c 89 f2             	mov    rdx,r14
    1403:	4c 89 ee             	mov    rsi,r13
    1406:	44 89 e7             	mov    edi,r12d
    1409:	41 ff 14 df          	call   QWORD PTR [r15+rbx*8]
    140d:	48 83 c3 01          	add    rbx,0x1
    1411:	48 39 dd             	cmp    rbp,rbx
    1414:	75 ea                	jne    1400 <__libc_csu_init+0x40>
    1416:	48 83 c4 08          	add    rsp,0x8
    141a:	5b                   	pop    rbx
    141b:	5d                   	pop    rbp
    141c:	41 5c                	pop    r12
    141e:	41 5d                	pop    r13
    1420:	41 5e                	pop    r14
    1422:	41 5f                	pop    r15
    1424:	c3                   	ret    
    1425:	66 66 2e 0f 1f 84 00 00 00 00 00 	data16 nop WORD PTR cs:[rax+rax*1+0x0]

0000000000001430 <__libc_csu_fini>:
__libc_csu_fini():
    1430:	f3 0f 1e fa          	endbr64 
    1434:	c3                   	ret    

Disassembly of section .fini:

0000000000001438 <_fini>:
_fini():
    1438:	f3 0f 1e fa          	endbr64 
    143c:	48 83 ec 08          	sub    rsp,0x8
    1440:	48 83 c4 08          	add    rsp,0x8
    1444:	c3                   	ret    
