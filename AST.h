/*-
* Copyright © 2022 Miss/Mr Gerallt Gersch Franke.
* All rights reserved.
* Description: ABSTRACT SYNTAX TREE COMPILER AND INTERPRETER.
* Licence: For the purposes of marking and educational uses only.
*          All rights reserved to the author.
*          For commercial use please send a cheque to geralltf at gmail.com.
* Abstract: Abstract Syntax Tree Compiler Theory.
*
*                                      '
*       [AST]                   . ` ;  ::
*                              , : +:;,,@
*                            '#:. '#` + @;
*            ;               :+:,.@#;'.; +,
*            `               '+;.'@'+@@ :@+
*           @              '+;;'+@@'@@' +@'@
*           @              :'::##@+##':@#@@''
*         +:+              #::;;@@,;@@+@##;@@:
*        @'##            ` +;###@#@''#.@@###@@+
*        '#@@            .`@+@#;+@';@@#+@'##@@@++
*       #@@@@            ++@++;;@':+;+:;@+++#@@+#+'
*       #@@@@#          ##@++#++:'+';@#@#:'';+@#;#;@
*      '@@ @@@,        #+#;@#@##;+.,@#@+@+;;''#@#;@+@
*      @#@@@@@#      `;@#@##@+##;#@,#@#@#@;:;;:+@@:@;#,
*      #@@@@@@@#    :'#,:+#'#++@#+#+;@@@@@;''::;'@#+,#'+
*     ,#@@@@@@@@@   ;'+@@;'#@+@#@@@@#+'@@@@;@@##::@;@;,'+
*     @#@@@@@@@@@@  :`+@###+;@';@'+;.`'@@@@@@@#@#@:@,@;:++
*    #@@@@@@@@@@@@@ #@;@#@@+'@'@+#@@@+@@@@@#@'@@#@@;@;@';@'
*    @@@@@    @@@@@@@++++@+'@@@@@@@#@@;+@@@###+@@@@@'#;+;'#@
*   +@@@@@@@@@@@@@@@#+@@@+@+;+@@,+@`@:+@@@###@+` @@@@#';+#;@;
*   @@@@@@@@@@@@@@@@@@;#'##+###@@#+@@@@'@@##@@@@      @';;@'#
*   @#@@@@@@@#@@@@@#@+#@+@#@;@@ FRANKE @@@##@@@#@     ,@:;'@;+
*  #@#@@@@@@@     +@@:#++#+@@@@@#@@@@@@@@@@@@@@@@     ;#@:;'@#+
*  @##@@@@@#       @@@@+#+##'@@@@@++@@#@@@@@@@@@###;   @#@;''#@,
*  @@@@@@@@        '@##'#@;#@@@@@@@@@@@@@@@   @@@@#+`  @@'@;'';@'
* ,@@ @@@,         @#+#@''',#@@@@@@@@@@@@@@@@@@@@@#@#' `@@'@'+''@++;
* @##@@@@          .@##+#+#;@@@@@@@@#@@@@@@#@@@#@@@@+@. @  ;''++'#'++
* @@@@@#           `#@#'+++`,+@@@@@#@@  +. #@@#  @@@##@ @   ;''.`'#+#+
* @@@@'             #@+@+:+`` @@@#@+`      @@@+    @@#++    ,@'+ @'++#
*'@@@@              #@##@#+# #@@@@         @@@'     @@@@'    '@++ '+##+
*@@@                @@@;@#'+,#@@+          @@@.      #@@@     '+'#+;++@'
*@@;                '@#@##'#'@ @           @@@        @@+      '''@'+++#:
*@@;                 ###@@@,#.             +#@        .@#,     ,''#''+++'
*@@                  `'@@'#@#.   ,         ###`        @++      ##' .;++#
*@@                +  :@@#+@,@+  ,     '   @@#+        ;#@:      '+   ++##
*@                  '  ++@.''::; '@   ;    ##@@:        #@:       +;   '++
*@                  `;   @;@#+' #@;  :     @##@+        @#'     +  +    '+
*                    +'; :@'':: +'  #+     +##@@:       @:+        +     +'
*                     @''#';@+++: ,.@      #@@@@+       ##'         .    :#
*                      `@+ `';;+@' ;,       @#@@#@       '+               +
*                       @@@ ',,+# @`        @@#@@#       @;               ,:
*                         #;+.'':,          @@#,@@;      @+                #
*                         :@#+.''`           @# @@@      @#                .
*                         '@#''#;             @ @@#      @+                 `
*                          @#@@#;             @:`@#      @#
*                           @@@+              @: @#      #+
*                            ''               @; '#      '+
*                            ,,               @. ,@      .++
*                            `                @`  @      .@
*                                             +   @       @
*                                                 .        '
**********************************************************  +  */

#ifndef AST_H
#define AST_H

// ABSTRACT SYNTAX TREE.

#include <string>
#include <list>
#include <queue>
#include <stack>

// Lexicon.
enum AST_ENUM_TOKEN
{
	AST_TOKEN_BEGIN						= 0xF000,
	AST_TOKEN_END						= 0x000F,
	AST_WHITESPACE						= 0x00,
	AST_COMMENT_BEGIN					= 0x01,
	AST_COMMENT_END						= 0x02,
	AST_MULTILINE_COMMENT_BEGIN			= 0x03,
	AST_MULTILINE_COMMENT_END			= 0x04,
	AST_SEMI_COLON						= 0x05,
	AST_VAR_TYPE						= 0x06,
	AST_VAR_SIG							= 0x07,
	AST_ASSIGN							= 0x08,
	AST_OP_PVE							= 0x09,
	AST_OP_SUB							= 0x0A,
	AST_OP_DIV							= 0x0B,
	AST_OP_MUL							= 0x0C,
	AST_FUN_DEF							= 0x0D, // FUNCTION SIGNATURE. void Function(int a, int b) {}
	AST_FUN_NAME						= 0x0E,	// FUNCTION NAME
	AST_FUN_TRAIT						= 0x0F,	// FUNCTION TRAIT
	AST_FUN_SPEC						= 0x10, // FUNCTION SPECIFICATION. void Function(int a, int b);
	AST_FUN_SCOPE_BEGIN					= 0x11,
	AST_FUN_SCOPE_END					= 0x12,
	AST_FUN_INVOKE						= 0x13, // F();
	AST_STRUCT_NAME						= 0x14, 
	AST_STRUCT_TYPE						= 0x15,
	AST_CLASS_NAME						= 0x16,
	AST_CLASS_TYPE						= 0x17,
	AST_CLASS_SCOPE_BEGIN				= 0x18,
	AST_CLASS_SCOPE_END					= 0x19,
	AST_TYPEDEF_KEYWORD					= 0x1A, // typedef type new_name_t
	AST_TYPEDEF_TYPE					= 0x1B,
	AST_TYPEDEF_DEFINITION				= 0x1C,

	AST_MULTILINE_WHITESPACE			= 0xFF,
	AST_TOKEN_WILDCARD					= 0xBAD, // Twaoken wild card is Uno.
	AST_UNDEFINED						= 0xFFFF

	//reserved keywords
	//preprocessor directive, macro, inline, class, function, scope, branch, enum, string, float, int, short, long, char/byte, bool, pointer arithmetic
	//sys library stuff; 1D array, 2D array, indicies, vectors, imaginary, integral, factorisation, anim curves, prime, mat, arithmetic, map, list, stack, heap, priority que, scene graph, db without file system, tex compr, temporal ADTs
};

enum AST_ENUM_TYPE
{
	AST_STRING							= 0x00,
	AST_BYTE							= 0x01,
	AST_INT								= 0x02,
	AST_UINT							= 0x03,
	AST_SHORT							= 0x04,
	AST_USHORT							= 0x05,
	AST_ULONG							= 0x06,
	AST_LONG							= 0x07,
	AST_FLOAT							= 0x08,
	AST_DOUBLE							= 0x09,
	AST_VAR								= 0x0A,
	AST_MAT3x3							= 0x0B,
	AST_MAT4x4							= 0x0C,
	AST_MAT8x8							= 0x0D,
	AST_MAT10x10						= 0x0E,
	AST_MAT12x12						= 0x0F,
	AST_MAT13x13						= 0x10,
	AST_MAT16x16						= 0x11,
	AST_MAT20x20						= 0x12,
	AST_MATNxN							= 0x13,
	AST_MATNxM							= 0x14,
	AST_MULTI_STRING					= 0xFF,
	AST_TYPE_UNDEFINED					= 0xFFF
};

enum AST_COMPILATION_MODE
{
	X86_RELEASE							= 0x00,
	X64_RELEASE							= 0x01,
	X86_DEBUG							= 0x02,
	X64_DEBUG							= 0x03,
};

typedef float				single_t;
typedef double				double_t;
typedef uint16_t			ushort_t;
typedef uint8_t				byte;
typedef byte				byte_p;

const char					C_EMPTY				= ""[0];
const char					C_NEWLINE_FEED		= '\n';
const char					C_COMMA				= ',';
const char					C_SPC				= ' ';
const char					C_RETURN			= '\r';
const int					Z_ZERO				= 0x00; // x64
const int					Z_ONE				= 0x01;
const int					Z_MINUS_ONE			= -0x01;
const uint64_t				Z_ZERO_U64			= 0;
const char*					C_EMPTY_CSTRING		= (char*)Z_ZERO;
const std::string			C_EMPTY_STRING		= "";
const std::string			C_COMMA_SPC			= "" + C_COMMA + C_SPC;
byte*						C_NULL_BYTE			= (byte*)nullptr;
void*						C_NULL				= nullptr;

#ifdef DEBUG_X64
AST_COMPILATION_MODE ast_compilation_mode = AST_COMPILATION_MODE::X64_DEBUG;
#define X64_TARGET
#endif

#ifdef DEBUG_X86
AST_COMPILATION_MODE ast_compilation_mode = AST_COMPILATION_MODE::X64_DEBUG;
#define X86_TARGET
#endif

#ifdef RELEASE_X64
AST_COMPILATION_MODE ast_compilation_mode = AST_COMPILATION_MODE::X64_RELEASE;
#define X64_TARGET
#endif

#ifdef RELEASE_X86
AST_COMPILATION_MODE ast_compilation_mode = AST_COMPILATION_MODE::X64_RELEASE;
#define X86_TARGET
#endif

// int a = 2;
// int b = 3;
// a +b

//   +
//  / \
// a   b

//   -
//  / \
// a   b

//   /
//  / \
// a   b

//   *
//  / \
// a   b


//		 =
//	  /	    \
// int a	 0

// a(-)b
// a+b-c
// (a+b)-c
// ((a+b)-c)
// F*2+1 // Function call.
// abs(-1)
// sin(3/5)
// vec2f(0,0).add(1)
// mat4f(1000,0100,0010,0001).det
// mat4f(1000,0100,0010,0001).det()
// mat4f(1000,0100,0010,0001).inverse
// ~mat4f(1000,0100,0010,0001)=

// hash table of signatures
// compute cluster

class AST_Compute_Result
{
private:

public:
	uint8_t* r_a_u8 = nullptr;
	uint16_t* r_b_u16 = nullptr;
	uint32_t* r_c_u32 = nullptr;
	uint64_t* r_d_u64 = nullptr;

	int8_t* r_e_i8 = nullptr;
	int16_t* r_f_i16 = nullptr;
	int32_t* r_g_i32 = nullptr;
	int64_t* r_h_i64 = nullptr;

	single_t* r_i_f = nullptr;
	double_t* r_j_d = nullptr;

	std::string* r_k_s = nullptr;

	AST_Compute_Result()
	{
		r_a_u8 = nullptr;
		r_b_u16 = nullptr;
		r_c_u32 = nullptr;
		r_d_u64 = nullptr;
		r_e_i8 = nullptr;
		r_f_i16 = nullptr;
		r_g_i32 = nullptr;
		r_h_i64 = nullptr;
		r_i_f = nullptr;
		r_j_d = nullptr;
		r_k_s = nullptr;
	}
	~AST_Compute_Result() {
		r_a_u8 = nullptr;
		r_b_u16 = nullptr;
		r_c_u32 = nullptr;
		r_d_u64 = nullptr;
		r_e_i8 = nullptr;
		r_f_i16 = nullptr;
		r_g_i32 = nullptr;
		r_h_i64 = nullptr;
		r_i_f = nullptr;
		r_j_d = nullptr;
		r_k_s = nullptr;
	}
	std::string to_string() {
		std::string clone = std::string(*r_k_s);
		delete r_k_s;
		r_k_s = nullptr;
		return clone;
	}
};

class Vector2i
{
public:
	int x = Z_ZERO;
	int y = Z_ZERO;
	Vector2i() {
		x = Z_ZERO;
		y = Z_ZERO;
	}
	Vector2i(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~Vector2i() {
		x = Z_ZERO;
		y = Z_ZERO;
	}
};

class AST_Node
{
private:

public:
	void*						data		= nullptr;								// Operand value.
	AST_Compute_Result*			precomputed = nullptr;
	void*						cache		= nullptr;
	AST_ENUM_TOKEN				type		= AST_ENUM_TOKEN::AST_UNDEFINED;		// Operator type.
	AST_ENUM_TYPE				ting		= AST_ENUM_TYPE::AST_TYPE_UNDEFINED;	// Quack.
	AST_Node*					left		= nullptr;							// Left branch program logic.
	AST_Node*					right		= nullptr;							// Right branch.
	//TODO: collections of ASTs to compliment trees.
	AST_Node(){
		data = nullptr;
		precomputed = nullptr;
		cache = nullptr;
		type = AST_ENUM_TOKEN::AST_UNDEFINED;
		ting = AST_ENUM_TYPE::AST_TYPE_UNDEFINED;
		left = nullptr;
		right = nullptr;
	}
	~AST_Node(){
		data = nullptr;
		precomputed = nullptr;
		cache = nullptr;
		type = AST_ENUM_TOKEN::AST_UNDEFINED;
		ting = AST_ENUM_TYPE::AST_TYPE_UNDEFINED;
		left = nullptr;
		right = nullptr;
	}
	void* d_left() {
		return left->data;
	}
	void* d_right() {
		return right->data;
	}
	int* d_left_int() {
		return (int*)left->data;
	}
	int* d_right_int() {
		return (int*)right->data;
	}
};

class AST
{
private:

public:
	AST_Node* program_root;
	AST() {
		program_root = nullptr;
	}
	~AST() {
		program_root = nullptr;
	}
	// Program analysis.
	// Type inference.
};

class AST_Binary_Stream {  // Binary stream editor with 32 or 64 bit addressing. 3D.
public:
	byte** underlying = nullptr;
#ifdef X64_TARGET
	uint64_t pos64 = Z_ZERO;
#endif
#ifdef X86_TARGET
	uint32_t pos = Z_ZERO;
#endif
#ifdef X64_TARGET
	uint64_t sz64 = Z_ZERO;
#endif
#ifdef X86_TARGET
	uint32_t sz = Z_ZERO;
#endif
	AST_Binary_Stream()
	{
		underlying = nullptr;
#ifdef X64_TARGET
		pos64 = Z_ZERO;
		sz64 = Z_ZERO;
#endif
#ifdef X86_TARGET
		pos = Z_ZERO;
		sz = Z_ZERO;
#endif
	}
	~AST_Binary_Stream() {
		underlying = nullptr;
#ifdef X64_TARGET
		pos64 = Z_ZERO;
		sz64 = Z_ZERO;
#endif
#ifdef X86_TARGET
		pos = Z_ZERO;
		sz = Z_ZERO;
#endif
	}
	// Set the current line for the stream reader to read from.
	void read_line(std::string line)
	{
		byte* p_byte;
		p_byte = (byte*)line.c_str();
		underlying = &p_byte;
#ifdef X64_TARGET
		sz64 = line.size();
#endif
#ifdef X86_TARGET
		sz = line.size();
#endif
	}
	// Check if the current stream has reached the end of the stream.
	bool stream_at_end()
	{
#ifdef X64_TARGET
		return pos64 >= sz64;
#endif
#ifdef X86_TARGET
		return pos >= sz;
#endif
	}
	byte fetch()
	{
		byte result;
#ifdef X64_TARGET
		result = *underlying[pos64];
#endif
#ifdef X86_TARGET
		result = underlying[pos];
#endif
		return result;
	}
	byte next() {
		byte r;

		r = Z_ZERO;

		/*
		IFs and switches are terrible people need to do better.
		AST_COMPILATION_MODE ast_compilation_mode
		{
			X64_RELEASE:		
			break;
		}
		*/

#ifdef X64_TARGET
		r = next64();
#endif
#ifdef X86_TARGET
		r = next32();
#endif
		return r;
	}

	// Advance to next byte in base memory stream.
	void next(byte** op_result) {
		byte r;
		r = next();
		(*op_result) = &r;
	}
#ifdef X64_TARGET
	// Advance to next byte in base memory stream.
	byte next64() {
		byte result;

		result = Z_ZERO;

		advance(pos64 + 1);

		result = *underlying[pos64];

		return result;
	}
	void increment() {
		advance(1);
	}
	void reverse()
	{
		advance(-1);
	}
	void advance(uint64_t offset) {
		uint64_t sstate = pos64 + offset;
		if (!(sstate <= 0) && (sstate >= sz64))
		{
			pos64 += offset;
		}
	}
	void backwards(uint64_t offset) {
		uint64_t sstate = pos64 - offset;
		if (!(sstate <= 0) && (sstate >= sz64))
		{
			pos64 -= offset;
		}
	}
	void set_position(uint64_t position) {
		pos64 = position;
	}
	// Find a byte given the specified 64 bit byte index.
	byte index_of(uint64_t byte_index) {
		byte result;
		uint64_t old_position;
		uint64_t i;

		i = 0;
		old_position = this->pos64;
		result = Z_ZERO;

		while (i < byte_index)
		{
			result = next();
		}

		this->pos64 = old_position;

		return result;
	}
	// Advance to the specified number of steps.
	void step(uint64_t step_pointer) {
		uint64_t i;

		i = 0;
		while (i < step_pointer)
		{
			next();
		}
	}
#endif
#ifdef X86_TARGET
	// Advance to next byte in base memory stream.
	byte next32() {
		byte result;

		result = Z_ZERO;

		advance(pos + 1);
		result = underlying[pos];
		return result;
	}
	void increment() {
		advance(1);
	}
	void reverse()
	{
		advance(-1);
	}
	void advance(uint32_t offset) {
		if (!(pos + offset <= 0))
		{
			pos += offset;
		}
	}
	void backwards(uint32_t offset) {
		uint32_t sstate = pos - offset;
		if (!(sstate <= 0) && (sstate >= sz))
		{
			pos -= offset;
		}
	}
	void set_position(uint32_t position) {
		pos = position;
	}
	// Find a byte given the specified 32 bit byte index.
	byte index_of(uint32_t byte_index) {
		byte result;
		uint32_t old_position;
		uint32_t i;

		i = 0;
		old_position = this->pos;
		result = Z_ZERO;

		while (i < byte_index)
		{
			result = next();
		}

		this->pos = old_position;

		return result;
	}
	// Advance to the specified number of steps.
	void step(uint32_t step_pointer) {
		uint32_t i;

		i = 0;
		while (i < step_pointer)
		{
			next();
		}
	}
#endif
	void reset() {
#ifdef X64_TARGET
		pos64 = Z_ZERO;
#endif
#ifdef X86_TARGET
		pos = Z_ZERO;
#endif		
	}
	void flush() { reset(); }
	void clear(){}
	void fill(byte value) {}
};

class AST_Program_Stream : AST_Binary_Stream // Factory of tokens.
{
private:
	std::string _program;
public:
	AST_Program_Stream()
	{
		_program = C_EMPTY;
	}
	AST_Program_Stream(std::string program) {
		_program = program;
	}
	~AST_Program_Stream(){
		_program = C_EMPTY;
	}
	bool is_empty()
	{
		bool is_null;
		char* source;
		source = (char*)_program.c_str();
		is_null = (source == nullptr) || _program == "" || *source == ""[0];
		source = nullptr;
		is_null = false;
		return is_null;
	}
	// Check if the current stream has reached the end of the stream in the base stream reader.
	bool stream_at_end()
	{
		return AST_Binary_Stream::stream_at_end();
	}
	// Set the current line for the base stream reader to read from.
	void read_line(std::string line)
	{
		AST_Binary_Stream::read_line(line);
	}
	// Advance to next byte in memory stream in underlying binary stream editor.
	byte next() {
		return AST_Binary_Stream::next();
	}
#ifdef X64_TARGET
	// Advance to next byte in base memory stream.
	byte next64() {
		return AST_Binary_Stream::next64();
	}
#endif
#ifdef X86_TARGET
	// Advance to next byte in base memory stream.
	byte next32() {
		return AST_Binary_Stream::next32();
	}
#endif
	void advance(uint32_t offset) {
		AST_Binary_Stream::advance(offset);
	}
	void advance(uint64_t offset) {
		AST_Binary_Stream::advance(offset);
	}
	void set_position(uint32_t position) {
		AST_Binary_Stream::set_position(position);
	}
	void set_position(uint64_t position) {
		AST_Binary_Stream::set_position(position);
	}
	void reset() {
		AST_Binary_Stream::reset();
	}
	void flush() { 
		AST_Binary_Stream::flush();
	}
	void clear() {
		AST_Binary_Stream::clear();
	}
	void fill(byte value) {
		AST_Binary_Stream::fill(value);
	}
	// Find a byte given the specified 32 bit byte index.
	byte index_of(uint32_t byte_index) {
		return AST_Binary_Stream::index_of(byte_index);
	}
	// Find a byte given the specified 64 bit byte index.
	byte index_of(uint64_t byte_index) {
		return AST_Binary_Stream::index_of(byte_index);
	}
	// Advance to the specified number of steps.
	void step(uint32_t step_pointer) {
		AST_Binary_Stream::step(step_pointer);
	}
	// Advance to the specified number of steps.
	void step(uint64_t step_pointer) {
		AST_Binary_Stream::step(step_pointer);
	}
#ifdef X64_TARGET
	std::string* get_string(uint32_t size, bool ignore_changes)
	{
		char** result;
		char* s_c;
		std::string* s;
		uint32_t i;

		s_c = (char*)malloc(sizeof(char) * size);
		s = new std::string(s_c, size);

		for (i = 0; i < size; i++)
		{
			*(s+i) = (char)next();
		}

		if (ignore_changes)
		{
			backwards(size);
		}

		return s;
	}
#endif
#ifdef X86_TARGET
	std::string* get_string(uint64_t size, bool ignore_changes)
	{
		char** result;
		std::string* s;
		uint64_t i;

		s = new std::string(nullptr, size);

		for (i = 0; i < size; i++)
		{
			s[i] = (char)next();
		}

		if (ignore_changes)
		{
			backwards(size);
		}

		return s;
	}
#endif

	void skip_to_token()
	{
		skip_to(true);
	}
	void skip_to_token_end()
	{
		skip_to_end(true);
	}
	void skip_to(bool try_token)
	{

	}
	void skip_to_end(bool try_token)
	{

	}
	AST_ENUM_TOKEN tokenise_one(byte b)
	{
		AST_ENUM_TOKEN t;
		t = AST_ENUM_TOKEN::AST_UNDEFINED;
		if (b == ';')
		{
			t = AST_ENUM_TOKEN::AST_SEMI_COLON;
		}
		if (b == ' ' || b == '\t' || b == '\n' || b == '\r')
		{
			t = AST_ENUM_TOKEN::AST_WHITESPACE;
		}
		if (b == '=')
		{
			t = AST_ENUM_TOKEN::AST_ASSIGN;
		}
		return t;
	}
	AST_ENUM_TOKEN tokenise_two(byte b0, byte b1)
	{
		AST_ENUM_TOKEN t;
		t = AST_ENUM_TOKEN::AST_UNDEFINED;
		if (b0 == '/' && b1 == '*')
		{
			t = AST_ENUM_TOKEN::AST_MULTILINE_COMMENT_BEGIN;
		}
		if (b0 == '*' && b1 == '/')
		{
			t = AST_ENUM_TOKEN::AST_MULTILINE_COMMENT_END;
		}
		if (b0 == '/' && b1 == '/')
		{
			t = AST_ENUM_TOKEN::AST_COMMENT_BEGIN;
		}
		return t;
	}
	AST_ENUM_TOKEN tokenise_var(AST_ENUM_TYPE* type)
	{
		AST_ENUM_TOKEN t;
		AST_ENUM_TYPE u;
		byte b0;
		byte b1;
		byte b2;
		std::string* var_type_p;
		std::string var_type;

		t = AST_ENUM_TOKEN::AST_UNDEFINED;
		u = AST_ENUM_TYPE::AST_TYPE_UNDEFINED;

		//b0 = next();
		//b1 = next();
		//b2 = next();

		//reverse();
		//reverse();
		//reverse();


		
		var_type_p = get_string(3, true);
		var_type = *var_type_p;

		if (var_type == "int")
		{
			t = AST_ENUM_TOKEN::AST_VAR_TYPE;
			u = AST_ENUM_TYPE::AST_INT;
		}

		if (var_type == "flo")
		{
			b0 = next();
			b1 = next();

			if (b0 == 'a' && b1 == 't')
			{
				t = AST_ENUM_TOKEN::AST_VAR_TYPE;
				u = AST_ENUM_TYPE::AST_FLOAT;
			}
		}

		(*type) = u;

		delete var_type_p;
		var_type_p = nullptr;

		increment();

		return t;
	}

	// TEST: Might not work with G++ compiler or clang++
#define F_VALIDATE_TK(t) if (t != AST_ENUM_TOKEN::AST_UNDEFINED) return t;
#define F_SINGLE_TOKENISE(b) t = tokenise_one(b); F_VALIDATE_TK(t);
#define F_DOUBLE_TOKENISE(b0,b1) t = tokenise_two(b0, b1); F_VALIDATE_TK(t);
#define F_VAR_TOKENISE(tv) t = tokenise_var(tv); return t;

	AST_ENUM_TOKEN capture(bool* is_commented_out) {
		AST_ENUM_TOKEN result;
		byte b0;
		byte b1;
		byte b2;
		AST_ENUM_TOKEN t;
		AST_ENUM_TOKEN s;
		AST_ENUM_TYPE type;
		bool b_is_commented_out;
		bool is_crcf;
		bool is_at_end;

		result = AST_ENUM_TOKEN::AST_UNDEFINED;
		s = AST_ENUM_TOKEN::AST_UNDEFINED;
		b_is_commented_out = *is_commented_out;

		//skip_to_token();
		//result = capture_token();
		//skip_to_token_end();

		b0 = next();
		b1 = next();
		b2 = next();
		
		reverse();
		reverse();
		reverse();

		increment();

		F_SINGLE_TOKENISE(b0);
		if (t == AST_ENUM_TOKEN::AST_COMMENT_BEGIN)
		{
			(*is_commented_out) = true;

			result = AST_ENUM_TOKEN::AST_COMMENT_BEGIN;
		}

		is_crcf = (b0 == C_NEWLINE_FEED || b0 == C_RETURN);
		is_at_end = (is_crcf || (is_crcf && stream_at_end()));

		if (is_at_end)
			//if ((b_is_commented_out && (b0 == '\n' || b0 == '\r')) || (b_is_commented_out && stream_at_end()))
		{
			(*is_commented_out) = false;

			result = AST_ENUM_TOKEN::AST_COMMENT_END;
		}

		F_DOUBLE_TOKENISE(b0, b1);

		s = F_VAR_TOKENISE(&type);
		
		if (s != AST_UNDEFINED)
		{
			t = s;
		}

			/*
	AST_TOKEN_BEGIN						= 0xF000,
	AST_TOKEN_END						= 0x000F,
	AST_WHITESPACE						= 0x00,
	AST_COMMENT_BEGIN					= 0x01,
	AST_COMMENT_END						= 0x02,
	AST_MULTILINE_COMMENT_BEGIN			= 0x03,
	AST_MULTILINE_COMMENT_END			= 0x04,
	AST_SEMI_COLON						= 0x05,
	AST_VAR_TYPE						= 0x06,
	AST_VAR_SIG							= 0x07,
	AST_ASSIGN							= 0x08,
	AST_OP_PVE							= 0x09,
	AST_OP_SUB							= 0x0A,
	AST_OP_DIV							= 0x0B,
	AST_OP_MUL							= 0x0C,
	AST_FUN_DEF							= 0x0D, // FUNCTION SIGNATURE. void Function(int a, int b) {}
	AST_FUN_NAME						= 0x0E,	// FUNCTION NAME
	AST_FUN_TRAIT						= 0x0F,	// FUNCTION TRAIT
	AST_FUN_SPEC						= 0x10, // FUNCTION SPECIFICATION. void Function(int a, int b);
	AST_FUN_SCOPE_BEGIN					= 0x11,
	AST_FUN_SCOPE_END					= 0x12,
	AST_FUN_INVOKE						= 0x13, // F();
	AST_STRUCT_NAME						= 0x14,
	AST_STRUCT_TYPE						= 0x15,
	AST_CLASS_NAME						= 0x16,
	AST_CLASS_TYPE						= 0x17,
	AST_CLASS_SCOPE_BEGIN				= 0x18,
	AST_CLASS_SCOPE_END					= 0x19,
	AST_TYPEDEF_KEYWORD					= 0x1A, // typedef type new_name_t
	AST_TYPEDEF_TYPE					= 0x1B,
	AST_TYPEDEF_DEFINITION				= 0x1C,

	AST_MULTILINE_WHITESPACE			= 0xFF,
	AST_TOKEN_WILDCARD					= 0xBAD, // Twaoken wild card is Uno.
	AST_UNDEFINED						= 0xFFFF
			*/

		return result;
	}
	AST_ENUM_TYPE grab() {
		return AST_ENUM_TYPE::AST_TYPE_UNDEFINED;
	}
	AST_ENUM_TOKEN* read_tokens()
	{
		AST_ENUM_TOKEN* tokens;
		AST_ENUM_TOKEN** out;

		read_tokens(out);

		tokens = *out;
		//out = nullptr;
		return tokens;
	}
	AST_ENUM_TYPE* read_types()
	{
		AST_ENUM_TYPE* types;
		AST_ENUM_TYPE** out;

		read_types(out);

		types = *out;
		return types;
	}
	// Read the set of all tokens found in the memory stream.
	void read_tokens(AST_ENUM_TOKEN** out)
	{
		AST_ENUM_TOKEN* tokens;
		const char* source;

		//tokens = new AST_ENUM_TOKEN[10];
		//tokens = (AST_ENUM_TOKEN*)malloc(sizeof(AST_ENUM_TOKEN) * 10);
		//free(tokens);

		source = _program.c_str();



		(*out) = tokens;
	}
	// Read the set of all types found in the memory stream.
	void read_types(AST_ENUM_TYPE** out)
	{

	}
	void emit_token(AST_ENUM_TOKEN opcode_type, AST_ENUM_TYPE* type)
	{
		//emit_token(opcode_type, nullptr);
	}
	// Reader/Writer.
};

class AST_Parser
{
private:
	std::string line;
	bool is_crlf(std::string multi_body_expression, int index) {
		char a;
		char b;
		bool is_new_line;
		bool is_crlf;
		int next;
		int c_count;

		b = multi_body_expression[index];
		next = index + Z_ONE;
		c_count = multi_body_expression.size();

		is_crlf = false;
		is_new_line = (b == C_NEWLINE_FEED || b == C_RETURN);

		if (!(next >= c_count)) {
			a = multi_body_expression[next];
			is_crlf = is_new_line || (a == C_NEWLINE_FEED || a == C_RETURN);
		}
		else
		{
			if (!is_new_line && (next >= c_count))
			{
				is_crlf = true;
			}
		}
		a = Z_ZERO;
		b = Z_ZERO;
		is_new_line = false;
		return is_crlf;
	}
	int get_max_line_length(std::string multi_body_expression) {
		int max_line_length;
		int line_index;
		bool reading_line;
		bool at_end;

		max_line_length = Z_ZERO;
		line_index = Z_ZERO;
		reading_line = true;

		do {
			at_end = line_index >= multi_body_expression.size() - 1;
			if (!is_crlf(multi_body_expression, line_index)) {
				max_line_length++;
			}
			else {
				reading_line = false;
			}
			if (at_end) {
				reading_line = false;
			}
			line_index++;
		} while (reading_line);

		line_index = Z_ZERO;
		reading_line = false;
		return max_line_length;
	}
public:
	AST_Parser() {}
	~AST_Parser() {}
	void read_line(std::string line)
	{
		this->line = line;
	}
	AST_ENUM_TOKEN tokeniser(AST_Program_Stream* token_buffer, uint32_t token_index, Vector2i line_offset, bool* is_commented_out) {
		return tokeniser(token_buffer, &token_index, line_offset, is_commented_out);
	}
	AST_ENUM_TOKEN tokeniser(AST_Program_Stream* token_buffer, uint64_t token_index, Vector2i line_offset, bool* is_commented_out) {
		return tokeniser(token_buffer, &token_index, line_offset, is_commented_out);
	}
	AST_ENUM_TOKEN tokeniser(AST_Program_Stream* token_buffer, void* token_index, Vector2i line_offset, bool* is_commented_out) {
		AST_ENUM_TOKEN current;
#ifdef X64_TARGET
		uint64_t step_pointer;
#endif
#ifdef X86_TARGET
		uint32_t step_pointer;
#endif
		current = AST_ENUM_TOKEN::AST_UNDEFINED;

		//std::string pos = ("" + line_offset.x + C_COMMA_SPC) + ("" + line_offset.y);
		//std::cout << pos << line << std::endl;

		//line = "int a = 0";
		if (token_buffer == nullptr)
		{
			token_buffer = new AST_Program_Stream(line);
		}

#ifdef X64_TARGET
		step_pointer = *(uint64_t*)token_index;
#endif
#ifdef X86_TARGET
		step_pointer = *(uint32_t*)token_index;
#endif
		token_buffer->step(step_pointer);

		current = token_buffer->capture(is_commented_out);

		return current;

	}
	AST_ENUM_TYPE typeify() {
		return AST_ENUM_TYPE::AST_TYPE_UNDEFINED;
	}
	AST_Node* make_node(AST_ENUM_TOKEN token, AST_Program_Stream* program_reader)
	{
		AST_Node* n;

		n = new AST_Node();
		n->left = nullptr;
		n->right = nullptr;
		
		program_reader->index_of(Z_ZERO_U64);

		//n->

		return n;
	}
	AST* parse(std::string multi_body_expression) {
		int index;
		int index2;
		int next;
		int line_end;
		AST* ast;
		AST_Node* root;
		AST_Node* node;
		AST_Program_Stream* program_reader;
		std::list<AST_ENUM_TOKEN>* lex_stream;
		std::list<AST_ENUM_TOKEN> types;
		const char* c_str;
		int c_count;
		char c;
		char n;
		int line_x;
		int line_y;
		int max_line_length = 0;
		int line_index = 0;
		std::string line;
		Vector2i line_xy;
		AST_ENUM_TOKEN token;
		bool is_commented_out;
		bool b_is_crlf;
#ifdef X64_TARGET
		uint64_t token_index;
#endif
#ifdef X86_TARGET
		uint32_t token_index;
#endif
		ast = new AST();
		program_reader = new AST_Program_Stream();
		lex_stream = new std::list<AST_ENUM_TOKEN>();
		c_str = multi_body_expression.c_str();
		c_count = multi_body_expression.size();
		line_x = Z_ZERO;
		line_y = Z_ONE;
		line_end = Z_ZERO;
		token_index = Z_ZERO;
		is_commented_out = false;
		b_is_crlf = false;

		for (index = 0; index < c_count; index++){
			c = multi_body_expression[index];

			next = index + Z_ONE;

			++line_x;
			++line_end;

			if (next >= c_count) {
				n = multi_body_expression[next];
			}
			else {
				n = C_EMPTY;
			}

			max_line_length = get_max_line_length(multi_body_expression);
			b_is_crlf = is_crlf(multi_body_expression, index);

			if (b_is_crlf || next - 1 >= c_count){
				auto x = b_is_crlf ? 0 : line_x;
				line = std::string(c_str + x, line_end);

				program_reader->read_line(line);

				for (index2 = 1; index2 < line_end; index2++)
				{
					line_x = index2;
					line_xy = Vector2i(line_x, line_y);

					token = tokeniser(program_reader, token_index, line_xy, &is_commented_out);

					if (token != AST_ENUM_TOKEN::AST_UNDEFINED)
					{
						lex_stream->push_back(token);
					}
					++token_index;
				}

				++line_y;

				line_x = Z_ZERO;
				line_end = Z_ZERO;
			}
		}

		AST_ENUM_TOKEN left = AST_ENUM_TOKEN::AST_UNDEFINED;
		AST_ENUM_TOKEN right = AST_ENUM_TOKEN::AST_UNDEFINED;
		size_t lex_count = lex_stream->size();
		AST_Node* child;
		root = nullptr;

		for (auto i = 0; i < lex_count; i++)
		{
			auto a = (lex_stream->begin()._Ptr + i);
			token = a->_Myval;

			if (i - 1 > 0)
			{
				right = (lex_stream->begin()._Ptr + i - 1)->_Myval;
			}

			if (i + 1 < lex_count)
			{
				right = (lex_stream->begin()._Ptr + i + 1)->_Myval;
			}

			if (token == AST_ENUM_TOKEN::AST_ASSIGN)
			{
				node = make_node(token, program_reader);

				if (node != nullptr)
				{
					if (left != AST_ENUM_TOKEN::AST_UNDEFINED)
					{
						child = make_node(left, program_reader);
						node->left = child;
					}
					if (right != AST_ENUM_TOKEN::AST_UNDEFINED)
					{
						child = make_node(right, program_reader);
						node->right = child;
					}
				}
				root = node;
				break;
			}
			if (token == AST_ENUM_TOKEN::AST_OP_PVE)
			{
				node = make_node(token, program_reader);

				if (node != nullptr)
				{
					
				}
			}
		}

		ast->program_root = root;
		index = Z_ZERO;
		next = Z_ZERO;
		line_end = Z_ZERO;
		c_str = nullptr;
		c_count = Z_ZERO;
		c = Z_ZERO;
		n = Z_ZERO;
		line_x = Z_ZERO;
		line_y = Z_ZERO;
		max_line_length = Z_ZERO;
		line_index = Z_ZERO;
		line = C_EMPTY;
		line_xy = Vector2i(0,0);
		token = AST_ENUM_TOKEN::AST_UNDEFINED;
		token_index = Z_ZERO;
		is_commented_out = false;
		b_is_crlf = false;

		delete program_reader;
		delete lex_stream;

		program_reader = nullptr;
		lex_stream = nullptr;

		return ast;
	}
};

class AST_Interpreter
{
private:
	AST* _expression_tree = nullptr;
	AST_Parser* _parser;
	std::stack<int*> _local_mem_i32;
	//std::stack<char**> _local_mem_sp;
	void prepass(AST_Node* node)
	{
		int result;
		char** boo;
		int a;
		int* b;
		int z;
		AST_ENUM_TOKEN token;

		token = node->type;

		switch (token) {
		case AST_ENUM_TOKEN::AST_WHITESPACE:
			break;
		case AST_ENUM_TOKEN::AST_COMMENT_BEGIN:
			break;
		case AST_ENUM_TOKEN::AST_COMMENT_END:
			break;
		case AST_ENUM_TOKEN::AST_VAR_TYPE:  // int 
			// Allocate memory for variable: next token in stream is signature name.
			a = Z_ZERO;
			b = &a;
			_local_mem_i32.push(b);
			//_local_mem_sp.push(name);
			break;
		case AST_ENUM_TOKEN::AST_VAR_SIG: // int name
			//boo = _local_mem_sp.top();
			break;
		case AST_ENUM_TOKEN::AST_ASSIGN: // int name =
			// DEFER assignment execution to next pass actual invocation execution.
			break;
		case AST_ENUM_TOKEN::AST_OP_PVE:
			result = *node->d_left_int() + *node->d_left_int();
			node->cache = &result;
			break;
		case AST_ENUM_TOKEN::AST_OP_SUB:
			result = *node->d_left_int() - *node->d_left_int();
			node->cache = &result;
			break;
		case AST_ENUM_TOKEN::AST_OP_DIV:
			result = *node->d_left_int() / *node->d_left_int();
			node->cache = &result;
			break;
		case AST_ENUM_TOKEN::AST_OP_MUL:
			result = (*node->d_left_int()) * (*node->d_left_int());
			node->cache = &result;
			break;
		case AST_ENUM_TOKEN::AST_FUN_DEF:

			break;
		case AST_ENUM_TOKEN::AST_FUN_NAME:

			break;
		case AST_ENUM_TOKEN::AST_FUN_TRAIT:

			break;
		case AST_ENUM_TOKEN::AST_FUN_SPEC:

			break;
		case AST_ENUM_TOKEN::AST_FUN_SCOPE_BEGIN:

			break;
		case AST_ENUM_TOKEN::AST_FUN_SCOPE_END:

			break;
		case AST_ENUM_TOKEN::AST_FUN_INVOKE:

			break;
		case AST_ENUM_TOKEN::AST_STRUCT_NAME:

			break;
		case AST_ENUM_TOKEN::AST_STRUCT_TYPE:

			break;
		case AST_ENUM_TOKEN::AST_CLASS_NAME:

			break;
		case AST_ENUM_TOKEN::AST_CLASS_TYPE:

			break;
		case AST_ENUM_TOKEN::AST_CLASS_SCOPE_BEGIN:

			break;
		case AST_ENUM_TOKEN::AST_CLASS_SCOPE_END:

			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_KEYWORD:

			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_TYPE:

			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_DEFINITION:

			break;
		case AST_ENUM_TOKEN::AST_MULTILINE_WHITESPACE:

			break;
		case AST_ENUM_TOKEN::AST_TOKEN_WILDCARD:

			break;
		case AST_ENUM_TOKEN::AST_UNDEFINED:
			// Throw exception saying invalid AST.
			break;
		}
		result = Z_ZERO;
		boo = nullptr;
		a = Z_ZERO;
		b = nullptr;
		z = Z_ZERO;
		token = AST_ENUM_TOKEN::AST_UNDEFINED;
	}
	void execute(AST_Node* node)
	{
		int result;
		char** boo;
		int a;
		int* b;
		int* c;
		int** d;
		int z;
		AST_ENUM_TOKEN token;
		std::string* s;

		token = node->type;

		switch (token) {
		case AST_ENUM_TOKEN::AST_WHITESPACE:
			break;
		case AST_ENUM_TOKEN::AST_COMMENT_BEGIN:
			break;
		case AST_ENUM_TOKEN::AST_COMMENT_END:
			break;
		case AST_ENUM_TOKEN::AST_VAR_TYPE:  // int 
			break;
		case AST_ENUM_TOKEN::AST_VAR_SIG: // int name
			break;
		case AST_ENUM_TOKEN::AST_ASSIGN: // int a = 0, Assign actual variable to precomputed value from prepass.
			b = _local_mem_i32.top();
			a = *b;

			c = (int*)node->cache;
			a = *c;

			//(*d) = c;

			if (node->precomputed == nullptr)
			{
				node->precomputed = new AST_Compute_Result();

				s = new std::string(""+a);
				node->precomputed->r_g_i32 = &a;
				node->precomputed->r_k_s = s;
			}

			// Deallocate last used memory.
			_local_mem_i32.pop();
			//_local_mem_sp.pop();
			break;
		case AST_ENUM_TOKEN::AST_OP_PVE:
			break;
		case AST_ENUM_TOKEN::AST_OP_SUB:
			break;
		case AST_ENUM_TOKEN::AST_OP_DIV:
			break;
		case AST_ENUM_TOKEN::AST_OP_MUL:
			break;
		case AST_ENUM_TOKEN::AST_FUN_DEF:
			break;
		case AST_ENUM_TOKEN::AST_FUN_NAME:
			break;
		case AST_ENUM_TOKEN::AST_FUN_TRAIT:
			break;
		case AST_ENUM_TOKEN::AST_FUN_SPEC:
			break;
		case AST_ENUM_TOKEN::AST_FUN_SCOPE_BEGIN:
			break;
		case AST_ENUM_TOKEN::AST_FUN_SCOPE_END:
			break;
		case AST_ENUM_TOKEN::AST_FUN_INVOKE:
			break;
		case AST_ENUM_TOKEN::AST_STRUCT_NAME:
			break;
		case AST_ENUM_TOKEN::AST_STRUCT_TYPE:
			break;
		case AST_ENUM_TOKEN::AST_CLASS_NAME:
			break;
		case AST_ENUM_TOKEN::AST_CLASS_TYPE:
			break;
		case AST_ENUM_TOKEN::AST_CLASS_SCOPE_BEGIN:
			break;
		case AST_ENUM_TOKEN::AST_CLASS_SCOPE_END:
			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_KEYWORD:
			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_TYPE:
			break;
		case AST_ENUM_TOKEN::AST_TYPEDEF_DEFINITION:
			break;
		case AST_ENUM_TOKEN::AST_MULTILINE_WHITESPACE:
			break;
		case AST_ENUM_TOKEN::AST_TOKEN_WILDCARD:
			break;
		case AST_ENUM_TOKEN::AST_UNDEFINED:
			break;
		}

		result = Z_ZERO;
		boo = nullptr;
		a = Z_ZERO;
		b = nullptr;
		c = nullptr;
		d = nullptr;
		z = Z_ZERO;
		token = AST_ENUM_TOKEN::AST_UNDEFINED;
		s = nullptr;
	}
public:
	AST_Interpreter(AST_Parser* parser) {
		this->_parser = parser;
		this->_expression_tree = nullptr;
	}
	~AST_Interpreter()
	{
		delete this->_expression_tree;
		delete this->_parser;

		this->_expression_tree = nullptr;
		this->_parser = nullptr;
	}
	void compile(std::string expression) {
		// Lexer, tokeniser, parser.
		this->_expression_tree = _parser->parse(expression);
	}
	void prepass_step(AST* ast)
	{
		void* n;
		AST_Node* node;

		std::queue<AST_Node*>* queue_p = new std::queue<AST_Node*>();
		std::queue<AST_Node*> queue = *queue_p;

		if (ast != nullptr) {
			queue.push(ast->program_root);

			while (!queue.empty()) {
				n = queue.front();
				node = (AST_Node*)n;

				prepass(node);

				if (node->left != nullptr) {
					queue.push(node->left);
				}

				if (node->right != nullptr) {
					queue.push(node->right);
				}
			}
		}

		n = nullptr;
		node = nullptr;
		delete queue_p;
		queue_p = nullptr;
	}
	AST_Compute_Result* run() {
		return run(_expression_tree);
	}
	AST_Compute_Result* run(AST* ast) {
		// Fetch, Decode, Execute.
		std::string* outcome;
		AST_Compute_Result* result = new AST_Compute_Result();
		void* n;
		AST_Node* node;
		std::queue<AST_Node*> queue;

		outcome = nullptr;

		if (ast != nullptr) {
			queue.push(ast->program_root);

			while (!queue.empty()) {
				n = queue.front();
				node = (AST_Node*)n;

				execute(node);

				if (node->left != nullptr) {
					queue.push(node->left);
				}

				if (node->right != nullptr) {
					queue.push(node->right);
				}
			}

			result->r_k_s = outcome;
		}
		else {
			result->r_k_s = nullptr;
		}

		return result;
	}
};

#endif

// They dropped out with a box of straps