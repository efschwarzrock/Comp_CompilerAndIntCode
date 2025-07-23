
// Generated from WPL.g4 by ANTLR 4.10.1


#include "WPLListener.h"
#include "WPLVisitor.h"

#include "WPLParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct WPLParserStaticData final {
  WPLParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  WPLParserStaticData(const WPLParserStaticData&) = delete;
  WPLParserStaticData(WPLParserStaticData&&) = delete;
  WPLParserStaticData& operator=(const WPLParserStaticData&) = delete;
  WPLParserStaticData& operator=(WPLParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

std::once_flag wplParserOnceFlag;
WPLParserStaticData *wplParserStaticData = nullptr;

void wplParserInitialize() {
  assert(wplParserStaticData == nullptr);
  auto staticData = std::make_unique<WPLParserStaticData>(
    std::vector<std::string>{
      "compilationUnit", "cuComponent", "varDeclaration", "scalarDeclaration", 
      "scalar", "arrayDeclaration", "type", "varInitializer", "externDeclaration", 
      "procedure", "procHeader", "externProcHeader", "function", "funcHeader", 
      "externFuncHeader", "params", "block", "statement", "loop", "conditional", 
      "select", "selectAlt", "call", "arguments", "arg", "return", "constant", 
      "assignment", "arrayIndex", "expr"
    },
    std::vector<std::string>{
      "", "'do'", "':'", "'boolean'", "'int'", "'str'", "'var'", "'proc'", 
      "'func'", "'extern'", "'return'", "'while'", "'select'", "'end'", 
      "'if'", "'then'", "'else'", "'length'", "'&'", "'<-'", "'='", "'>='", 
      "'>'", "'<='", "'<'", "'-'", "'~='", "'|'", "'+'", "'/'", "'*'", "'~'", 
      "','", "';'", "'...'", "'.'", "'['", "']'", "'('", "')'", "'{'", "'}'"
    },
    std::vector<std::string>{
      "", "", "", "BOOL", "INT", "STR", "VAR", "PROC", "FUNC", "EXTERN", 
      "RETURN", "WHILE", "SELECT", "END", "IF", "THEN", "ELSE", "LENGTH", 
      "AND", "ASSIGN", "EQUAL", "GEQ", "GTR", "LEQ", "LESS", "MINUS", "NEQ", 
      "OR", "PLUS", "DIV", "MUL", "NOT", "COMMA", "SEMICOLON", "ELLIPSIS", 
      "DOT", "LBRACKET", "RBRACKET", "LPAR", "RPAR", "LBRACE", "RBRACE", 
      "WS", "INTEGER", "BOOLEAN", "ID", "STRING", "COMMENT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,47,344,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,1,0,4,0,62,8,0,11,0,12,0,63,1,0,1,0,1,1,1,1,1,1,1,1,3,1,
  	72,8,1,1,2,1,2,3,2,76,8,2,1,3,1,3,3,3,80,8,3,1,3,1,3,1,3,5,3,85,8,3,10,
  	3,12,3,88,9,3,1,3,1,3,1,4,1,4,3,4,94,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,
  	1,6,1,6,1,7,1,7,1,7,1,8,1,8,1,8,3,8,111,8,8,1,8,1,8,1,9,1,9,1,9,1,10,
  	1,10,1,10,1,10,3,10,122,8,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,11,
  	1,11,1,11,3,11,134,8,11,1,11,3,11,137,8,11,3,11,139,8,11,1,11,1,11,1,
  	12,1,12,1,12,1,13,1,13,1,13,1,13,1,13,3,13,151,8,13,1,13,1,13,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,3,14,164,8,14,1,14,3,14,167,8,14,
  	3,14,169,8,14,1,14,1,14,1,15,1,15,1,15,1,15,1,15,1,15,5,15,179,8,15,10,
  	15,12,15,182,9,15,1,16,1,16,1,16,1,16,4,16,188,8,16,11,16,12,16,189,1,
  	16,1,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,203,8,17,1,
  	18,1,18,1,18,1,18,1,18,1,19,1,19,1,19,3,19,213,8,19,1,19,1,19,1,19,3,
  	19,218,8,19,1,20,1,20,1,20,4,20,223,8,20,11,20,12,20,224,1,20,1,20,1,
  	21,1,21,1,21,1,21,1,22,1,22,1,22,3,22,236,8,22,1,22,1,22,1,23,1,23,1,
  	23,5,23,243,8,23,10,23,12,23,246,9,23,1,24,1,24,3,24,250,8,24,1,25,1,
  	25,3,25,254,8,25,1,25,1,25,1,26,1,26,1,27,1,27,1,27,5,27,263,8,27,10,
  	27,12,27,266,9,27,1,27,1,27,1,27,1,27,5,27,272,8,27,10,27,12,27,275,9,
  	27,1,27,1,27,1,27,1,27,1,27,1,27,1,27,3,27,284,8,27,1,28,1,28,1,28,1,
  	28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,5,29,297,8,29,10,29,12,29,300,9,
  	29,3,29,302,8,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,3,29,319,8,29,1,29,1,29,1,29,1,29,1,29,1,29,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,5,29,339,8,
  	29,10,29,12,29,342,9,29,1,29,0,1,58,30,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,0,6,1,0,3,5,2,0,
  	43,44,46,46,1,0,29,30,2,0,25,25,28,28,1,0,21,24,2,0,20,20,26,26,367,0,
  	61,1,0,0,0,2,71,1,0,0,0,4,75,1,0,0,0,6,79,1,0,0,0,8,91,1,0,0,0,10,95,
  	1,0,0,0,12,102,1,0,0,0,14,104,1,0,0,0,16,107,1,0,0,0,18,114,1,0,0,0,20,
  	117,1,0,0,0,22,125,1,0,0,0,24,142,1,0,0,0,26,145,1,0,0,0,28,154,1,0,0,
  	0,30,172,1,0,0,0,32,183,1,0,0,0,34,202,1,0,0,0,36,204,1,0,0,0,38,209,
  	1,0,0,0,40,219,1,0,0,0,42,228,1,0,0,0,44,232,1,0,0,0,46,239,1,0,0,0,48,
  	249,1,0,0,0,50,251,1,0,0,0,52,257,1,0,0,0,54,283,1,0,0,0,56,285,1,0,0,
  	0,58,318,1,0,0,0,60,62,3,2,1,0,61,60,1,0,0,0,62,63,1,0,0,0,63,61,1,0,
  	0,0,63,64,1,0,0,0,64,65,1,0,0,0,65,66,5,0,0,1,66,1,1,0,0,0,67,72,3,4,
  	2,0,68,72,3,18,9,0,69,72,3,24,12,0,70,72,3,16,8,0,71,67,1,0,0,0,71,68,
  	1,0,0,0,71,69,1,0,0,0,71,70,1,0,0,0,72,3,1,0,0,0,73,76,3,6,3,0,74,76,
  	3,10,5,0,75,73,1,0,0,0,75,74,1,0,0,0,76,5,1,0,0,0,77,80,3,12,6,0,78,80,
  	5,6,0,0,79,77,1,0,0,0,79,78,1,0,0,0,80,81,1,0,0,0,81,86,3,8,4,0,82,83,
  	5,32,0,0,83,85,3,8,4,0,84,82,1,0,0,0,85,88,1,0,0,0,86,84,1,0,0,0,86,87,
  	1,0,0,0,87,89,1,0,0,0,88,86,1,0,0,0,89,90,5,33,0,0,90,7,1,0,0,0,91,93,
  	5,45,0,0,92,94,3,14,7,0,93,92,1,0,0,0,93,94,1,0,0,0,94,9,1,0,0,0,95,96,
  	3,12,6,0,96,97,5,36,0,0,97,98,5,43,0,0,98,99,5,37,0,0,99,100,5,45,0,0,
  	100,101,5,33,0,0,101,11,1,0,0,0,102,103,7,0,0,0,103,13,1,0,0,0,104,105,
  	5,19,0,0,105,106,3,52,26,0,106,15,1,0,0,0,107,110,5,9,0,0,108,111,3,22,
  	11,0,109,111,3,28,14,0,110,108,1,0,0,0,110,109,1,0,0,0,111,112,1,0,0,
  	0,112,113,5,33,0,0,113,17,1,0,0,0,114,115,3,20,10,0,115,116,3,32,16,0,
  	116,19,1,0,0,0,117,118,5,7,0,0,118,119,5,45,0,0,119,121,5,38,0,0,120,
  	122,3,30,15,0,121,120,1,0,0,0,121,122,1,0,0,0,122,123,1,0,0,0,123,124,
  	5,39,0,0,124,21,1,0,0,0,125,126,5,7,0,0,126,127,5,45,0,0,127,138,5,38,
  	0,0,128,129,3,30,15,0,129,130,5,32,0,0,130,131,5,34,0,0,131,139,1,0,0,
  	0,132,134,3,30,15,0,133,132,1,0,0,0,133,134,1,0,0,0,134,139,1,0,0,0,135,
  	137,5,34,0,0,136,135,1,0,0,0,136,137,1,0,0,0,137,139,1,0,0,0,138,128,
  	1,0,0,0,138,133,1,0,0,0,138,136,1,0,0,0,139,140,1,0,0,0,140,141,5,39,
  	0,0,141,23,1,0,0,0,142,143,3,26,13,0,143,144,3,32,16,0,144,25,1,0,0,0,
  	145,146,3,12,6,0,146,147,5,8,0,0,147,148,5,45,0,0,148,150,5,38,0,0,149,
  	151,3,30,15,0,150,149,1,0,0,0,150,151,1,0,0,0,151,152,1,0,0,0,152,153,
  	5,39,0,0,153,27,1,0,0,0,154,155,3,12,6,0,155,156,5,8,0,0,156,157,5,45,
  	0,0,157,168,5,38,0,0,158,159,3,30,15,0,159,160,5,32,0,0,160,161,5,34,
  	0,0,161,169,1,0,0,0,162,164,3,30,15,0,163,162,1,0,0,0,163,164,1,0,0,0,
  	164,169,1,0,0,0,165,167,5,34,0,0,166,165,1,0,0,0,166,167,1,0,0,0,167,
  	169,1,0,0,0,168,158,1,0,0,0,168,163,1,0,0,0,168,166,1,0,0,0,169,170,1,
  	0,0,0,170,171,5,39,0,0,171,29,1,0,0,0,172,173,3,12,6,0,173,180,5,45,0,
  	0,174,175,5,32,0,0,175,176,3,12,6,0,176,177,5,45,0,0,177,179,1,0,0,0,
  	178,174,1,0,0,0,179,182,1,0,0,0,180,178,1,0,0,0,180,181,1,0,0,0,181,31,
  	1,0,0,0,182,180,1,0,0,0,183,187,5,40,0,0,184,188,3,34,17,0,185,188,3,
  	4,2,0,186,188,3,32,16,0,187,184,1,0,0,0,187,185,1,0,0,0,187,186,1,0,0,
  	0,188,189,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,191,1,0,0,0,191,
  	192,5,41,0,0,192,33,1,0,0,0,193,203,3,54,27,0,194,203,3,36,18,0,195,203,
  	3,40,20,0,196,203,3,38,19,0,197,198,3,44,22,0,198,199,5,33,0,0,199,203,
  	1,0,0,0,200,203,3,32,16,0,201,203,3,50,25,0,202,193,1,0,0,0,202,194,1,
  	0,0,0,202,195,1,0,0,0,202,196,1,0,0,0,202,197,1,0,0,0,202,200,1,0,0,0,
  	202,201,1,0,0,0,203,35,1,0,0,0,204,205,5,11,0,0,205,206,3,58,29,0,206,
  	207,5,1,0,0,207,208,3,32,16,0,208,37,1,0,0,0,209,210,5,14,0,0,210,212,
  	3,58,29,0,211,213,5,15,0,0,212,211,1,0,0,0,212,213,1,0,0,0,213,214,1,
  	0,0,0,214,217,3,32,16,0,215,216,5,16,0,0,216,218,3,32,16,0,217,215,1,
  	0,0,0,217,218,1,0,0,0,218,39,1,0,0,0,219,220,5,12,0,0,220,222,5,40,0,
  	0,221,223,3,42,21,0,222,221,1,0,0,0,223,224,1,0,0,0,224,222,1,0,0,0,224,
  	225,1,0,0,0,225,226,1,0,0,0,226,227,5,41,0,0,227,41,1,0,0,0,228,229,3,
  	58,29,0,229,230,5,2,0,0,230,231,3,34,17,0,231,43,1,0,0,0,232,233,5,45,
  	0,0,233,235,5,38,0,0,234,236,3,46,23,0,235,234,1,0,0,0,235,236,1,0,0,
  	0,236,237,1,0,0,0,237,238,5,39,0,0,238,45,1,0,0,0,239,244,3,48,24,0,240,
  	241,5,32,0,0,241,243,3,48,24,0,242,240,1,0,0,0,243,246,1,0,0,0,244,242,
  	1,0,0,0,244,245,1,0,0,0,245,47,1,0,0,0,246,244,1,0,0,0,247,250,5,45,0,
  	0,248,250,3,52,26,0,249,247,1,0,0,0,249,248,1,0,0,0,250,49,1,0,0,0,251,
  	253,5,10,0,0,252,254,3,58,29,0,253,252,1,0,0,0,253,254,1,0,0,0,254,255,
  	1,0,0,0,255,256,5,33,0,0,256,51,1,0,0,0,257,258,7,1,0,0,258,53,1,0,0,
  	0,259,264,5,45,0,0,260,261,5,32,0,0,261,263,5,45,0,0,262,260,1,0,0,0,
  	263,266,1,0,0,0,264,262,1,0,0,0,264,265,1,0,0,0,265,267,1,0,0,0,266,264,
  	1,0,0,0,267,268,5,19,0,0,268,273,3,58,29,0,269,270,5,32,0,0,270,272,3,
  	58,29,0,271,269,1,0,0,0,272,275,1,0,0,0,273,271,1,0,0,0,273,274,1,0,0,
  	0,274,276,1,0,0,0,275,273,1,0,0,0,276,277,5,33,0,0,277,284,1,0,0,0,278,
  	279,3,56,28,0,279,280,5,19,0,0,280,281,3,58,29,0,281,282,5,33,0,0,282,
  	284,1,0,0,0,283,259,1,0,0,0,283,278,1,0,0,0,284,55,1,0,0,0,285,286,5,
  	45,0,0,286,287,5,36,0,0,287,288,3,58,29,0,288,289,5,37,0,0,289,57,1,0,
  	0,0,290,291,6,29,-1,0,291,292,5,45,0,0,292,301,5,38,0,0,293,298,3,58,
  	29,0,294,295,5,32,0,0,295,297,3,58,29,0,296,294,1,0,0,0,297,300,1,0,0,
  	0,298,296,1,0,0,0,298,299,1,0,0,0,299,302,1,0,0,0,300,298,1,0,0,0,301,
  	293,1,0,0,0,301,302,1,0,0,0,302,303,1,0,0,0,303,319,5,39,0,0,304,319,
  	3,56,28,0,305,306,5,25,0,0,306,319,3,58,29,12,307,308,5,31,0,0,308,319,
  	3,58,29,11,309,310,5,38,0,0,310,311,3,58,29,0,311,312,5,39,0,0,312,319,
  	1,0,0,0,313,314,5,45,0,0,314,315,5,35,0,0,315,319,5,17,0,0,316,319,5,
  	45,0,0,317,319,3,52,26,0,318,290,1,0,0,0,318,304,1,0,0,0,318,305,1,0,
  	0,0,318,307,1,0,0,0,318,309,1,0,0,0,318,313,1,0,0,0,318,316,1,0,0,0,318,
  	317,1,0,0,0,319,340,1,0,0,0,320,321,10,10,0,0,321,322,7,2,0,0,322,339,
  	3,58,29,11,323,324,10,9,0,0,324,325,7,3,0,0,325,339,3,58,29,10,326,327,
  	10,8,0,0,327,328,7,4,0,0,328,339,3,58,29,9,329,330,10,7,0,0,330,331,7,
  	5,0,0,331,339,3,58,29,7,332,333,10,6,0,0,333,334,5,18,0,0,334,339,3,58,
  	29,7,335,336,10,5,0,0,336,337,5,27,0,0,337,339,3,58,29,6,338,320,1,0,
  	0,0,338,323,1,0,0,0,338,326,1,0,0,0,338,329,1,0,0,0,338,332,1,0,0,0,338,
  	335,1,0,0,0,339,342,1,0,0,0,340,338,1,0,0,0,340,341,1,0,0,0,341,59,1,
  	0,0,0,342,340,1,0,0,0,34,63,71,75,79,86,93,110,121,133,136,138,150,163,
  	166,168,180,187,189,202,212,217,224,235,244,249,253,264,273,283,298,301,
  	318,338,340
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  wplParserStaticData = staticData.release();
}

}

WPLParser::WPLParser(TokenStream *input) : WPLParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

WPLParser::WPLParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  WPLParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *wplParserStaticData->atn, wplParserStaticData->decisionToDFA, wplParserStaticData->sharedContextCache, options);
}

WPLParser::~WPLParser() {
  delete _interpreter;
}

const atn::ATN& WPLParser::getATN() const {
  return *wplParserStaticData->atn;
}

std::string WPLParser::getGrammarFileName() const {
  return "WPL.g4";
}

const std::vector<std::string>& WPLParser::getRuleNames() const {
  return wplParserStaticData->ruleNames;
}

const dfa::Vocabulary& WPLParser::getVocabulary() const {
  return wplParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView WPLParser::getSerializedATN() const {
  return wplParserStaticData->serializedATN;
}


//----------------- CompilationUnitContext ------------------------------------------------------------------

WPLParser::CompilationUnitContext::CompilationUnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::CompilationUnitContext::EOF() {
  return getToken(WPLParser::EOF, 0);
}

std::vector<WPLParser::CuComponentContext *> WPLParser::CompilationUnitContext::cuComponent() {
  return getRuleContexts<WPLParser::CuComponentContext>();
}

WPLParser::CuComponentContext* WPLParser::CompilationUnitContext::cuComponent(size_t i) {
  return getRuleContext<WPLParser::CuComponentContext>(i);
}


size_t WPLParser::CompilationUnitContext::getRuleIndex() const {
  return WPLParser::RuleCompilationUnit;
}

void WPLParser::CompilationUnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompilationUnit(this);
}

void WPLParser::CompilationUnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompilationUnit(this);
}


std::any WPLParser::CompilationUnitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitCompilationUnit(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::CompilationUnitContext* WPLParser::compilationUnit() {
  CompilationUnitContext *_localctx = _tracker.createInstance<CompilationUnitContext>(_ctx, getState());
  enterRule(_localctx, 0, WPLParser::RuleCompilationUnit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(60);
      cuComponent();
      setState(63); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
      | (1ULL << WPLParser::INT)
      | (1ULL << WPLParser::STR)
      | (1ULL << WPLParser::VAR)
      | (1ULL << WPLParser::PROC)
      | (1ULL << WPLParser::EXTERN))) != 0));
    setState(65);
    match(WPLParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CuComponentContext ------------------------------------------------------------------

WPLParser::CuComponentContext::CuComponentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::VarDeclarationContext* WPLParser::CuComponentContext::varDeclaration() {
  return getRuleContext<WPLParser::VarDeclarationContext>(0);
}

WPLParser::ProcedureContext* WPLParser::CuComponentContext::procedure() {
  return getRuleContext<WPLParser::ProcedureContext>(0);
}

WPLParser::FunctionContext* WPLParser::CuComponentContext::function() {
  return getRuleContext<WPLParser::FunctionContext>(0);
}

WPLParser::ExternDeclarationContext* WPLParser::CuComponentContext::externDeclaration() {
  return getRuleContext<WPLParser::ExternDeclarationContext>(0);
}


size_t WPLParser::CuComponentContext::getRuleIndex() const {
  return WPLParser::RuleCuComponent;
}

void WPLParser::CuComponentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCuComponent(this);
}

void WPLParser::CuComponentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCuComponent(this);
}


std::any WPLParser::CuComponentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitCuComponent(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::CuComponentContext* WPLParser::cuComponent() {
  CuComponentContext *_localctx = _tracker.createInstance<CuComponentContext>(_ctx, getState());
  enterRule(_localctx, 2, WPLParser::RuleCuComponent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(67);
      varDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(68);
      procedure();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(69);
      function();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(70);
      externDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

WPLParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::ScalarDeclarationContext* WPLParser::VarDeclarationContext::scalarDeclaration() {
  return getRuleContext<WPLParser::ScalarDeclarationContext>(0);
}

WPLParser::ArrayDeclarationContext* WPLParser::VarDeclarationContext::arrayDeclaration() {
  return getRuleContext<WPLParser::ArrayDeclarationContext>(0);
}


size_t WPLParser::VarDeclarationContext::getRuleIndex() const {
  return WPLParser::RuleVarDeclaration;
}

void WPLParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void WPLParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}


std::any WPLParser::VarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitVarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::VarDeclarationContext* WPLParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, WPLParser::RuleVarDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(73);
      scalarDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(74);
      arrayDeclaration();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarDeclarationContext ------------------------------------------------------------------

WPLParser::ScalarDeclarationContext::ScalarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ScalarDeclarationContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

std::vector<WPLParser::ScalarContext *> WPLParser::ScalarDeclarationContext::scalar() {
  return getRuleContexts<WPLParser::ScalarContext>();
}

WPLParser::ScalarContext* WPLParser::ScalarDeclarationContext::scalar(size_t i) {
  return getRuleContext<WPLParser::ScalarContext>(i);
}

tree::TerminalNode* WPLParser::ScalarDeclarationContext::VAR() {
  return getToken(WPLParser::VAR, 0);
}

WPLParser::TypeContext* WPLParser::ScalarDeclarationContext::type() {
  return getRuleContext<WPLParser::TypeContext>(0);
}

std::vector<tree::TerminalNode *> WPLParser::ScalarDeclarationContext::COMMA() {
  return getTokens(WPLParser::COMMA);
}

tree::TerminalNode* WPLParser::ScalarDeclarationContext::COMMA(size_t i) {
  return getToken(WPLParser::COMMA, i);
}


size_t WPLParser::ScalarDeclarationContext::getRuleIndex() const {
  return WPLParser::RuleScalarDeclaration;
}

void WPLParser::ScalarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScalarDeclaration(this);
}

void WPLParser::ScalarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScalarDeclaration(this);
}


std::any WPLParser::ScalarDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitScalarDeclaration(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ScalarDeclarationContext* WPLParser::scalarDeclaration() {
  ScalarDeclarationContext *_localctx = _tracker.createInstance<ScalarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, WPLParser::RuleScalarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(79);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WPLParser::BOOL:
      case WPLParser::INT:
      case WPLParser::STR: {
        setState(77);
        antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->t = type();
        break;
      }

      case WPLParser::VAR: {
        setState(78);
        match(WPLParser::VAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(81);
    antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalarContext = scalar();
    antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalars.push_back(antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalarContext);
    setState(86);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WPLParser::COMMA) {
      setState(82);
      match(WPLParser::COMMA);
      setState(83);
      antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalarContext = scalar();
      antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalars.push_back(antlrcpp::downCast<ScalarDeclarationContext *>(_localctx)->scalarContext);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(89);
    match(WPLParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarContext ------------------------------------------------------------------

WPLParser::ScalarContext::ScalarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ScalarContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::VarInitializerContext* WPLParser::ScalarContext::varInitializer() {
  return getRuleContext<WPLParser::VarInitializerContext>(0);
}


size_t WPLParser::ScalarContext::getRuleIndex() const {
  return WPLParser::RuleScalar;
}

void WPLParser::ScalarContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterScalar(this);
}

void WPLParser::ScalarContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitScalar(this);
}


std::any WPLParser::ScalarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitScalar(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ScalarContext* WPLParser::scalar() {
  ScalarContext *_localctx = _tracker.createInstance<ScalarContext>(_ctx, getState());
  enterRule(_localctx, 8, WPLParser::RuleScalar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(WPLParser::ID);
    setState(93);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WPLParser::ASSIGN) {
      setState(92);
      varInitializer();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayDeclarationContext ------------------------------------------------------------------

WPLParser::ArrayDeclarationContext::ArrayDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ArrayDeclarationContext::LBRACKET() {
  return getToken(WPLParser::LBRACKET, 0);
}

tree::TerminalNode* WPLParser::ArrayDeclarationContext::INTEGER() {
  return getToken(WPLParser::INTEGER, 0);
}

tree::TerminalNode* WPLParser::ArrayDeclarationContext::RBRACKET() {
  return getToken(WPLParser::RBRACKET, 0);
}

tree::TerminalNode* WPLParser::ArrayDeclarationContext::ID() {
  return getToken(WPLParser::ID, 0);
}

tree::TerminalNode* WPLParser::ArrayDeclarationContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

WPLParser::TypeContext* WPLParser::ArrayDeclarationContext::type() {
  return getRuleContext<WPLParser::TypeContext>(0);
}


size_t WPLParser::ArrayDeclarationContext::getRuleIndex() const {
  return WPLParser::RuleArrayDeclaration;
}

void WPLParser::ArrayDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDeclaration(this);
}

void WPLParser::ArrayDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDeclaration(this);
}


std::any WPLParser::ArrayDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitArrayDeclaration(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ArrayDeclarationContext* WPLParser::arrayDeclaration() {
  ArrayDeclarationContext *_localctx = _tracker.createInstance<ArrayDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, WPLParser::RuleArrayDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    antlrcpp::downCast<ArrayDeclarationContext *>(_localctx)->typename_ = type();
    setState(96);
    match(WPLParser::LBRACKET);
    setState(97);
    match(WPLParser::INTEGER);
    setState(98);
    match(WPLParser::RBRACKET);
    setState(99);
    match(WPLParser::ID);
    setState(100);
    match(WPLParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

WPLParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::TypeContext::BOOL() {
  return getToken(WPLParser::BOOL, 0);
}

tree::TerminalNode* WPLParser::TypeContext::INT() {
  return getToken(WPLParser::INT, 0);
}

tree::TerminalNode* WPLParser::TypeContext::STR() {
  return getToken(WPLParser::STR, 0);
}


size_t WPLParser::TypeContext::getRuleIndex() const {
  return WPLParser::RuleType;
}

void WPLParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void WPLParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}


std::any WPLParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::TypeContext* WPLParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 12, WPLParser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(102);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
      | (1ULL << WPLParser::INT)
      | (1ULL << WPLParser::STR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarInitializerContext ------------------------------------------------------------------

WPLParser::VarInitializerContext::VarInitializerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::VarInitializerContext::ASSIGN() {
  return getToken(WPLParser::ASSIGN, 0);
}

WPLParser::ConstantContext* WPLParser::VarInitializerContext::constant() {
  return getRuleContext<WPLParser::ConstantContext>(0);
}


size_t WPLParser::VarInitializerContext::getRuleIndex() const {
  return WPLParser::RuleVarInitializer;
}

void WPLParser::VarInitializerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarInitializer(this);
}

void WPLParser::VarInitializerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarInitializer(this);
}


std::any WPLParser::VarInitializerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitVarInitializer(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::VarInitializerContext* WPLParser::varInitializer() {
  VarInitializerContext *_localctx = _tracker.createInstance<VarInitializerContext>(_ctx, getState());
  enterRule(_localctx, 14, WPLParser::RuleVarInitializer);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(104);
    match(WPLParser::ASSIGN);
    setState(105);
    antlrcpp::downCast<VarInitializerContext *>(_localctx)->c = constant();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternDeclarationContext ------------------------------------------------------------------

WPLParser::ExternDeclarationContext::ExternDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ExternDeclarationContext::EXTERN() {
  return getToken(WPLParser::EXTERN, 0);
}

tree::TerminalNode* WPLParser::ExternDeclarationContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

WPLParser::ExternProcHeaderContext* WPLParser::ExternDeclarationContext::externProcHeader() {
  return getRuleContext<WPLParser::ExternProcHeaderContext>(0);
}

WPLParser::ExternFuncHeaderContext* WPLParser::ExternDeclarationContext::externFuncHeader() {
  return getRuleContext<WPLParser::ExternFuncHeaderContext>(0);
}


size_t WPLParser::ExternDeclarationContext::getRuleIndex() const {
  return WPLParser::RuleExternDeclaration;
}

void WPLParser::ExternDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternDeclaration(this);
}

void WPLParser::ExternDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternDeclaration(this);
}


std::any WPLParser::ExternDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitExternDeclaration(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ExternDeclarationContext* WPLParser::externDeclaration() {
  ExternDeclarationContext *_localctx = _tracker.createInstance<ExternDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, WPLParser::RuleExternDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(107);
    match(WPLParser::EXTERN);
    setState(110);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WPLParser::PROC: {
        setState(108);
        externProcHeader();
        break;
      }

      case WPLParser::BOOL:
      case WPLParser::INT:
      case WPLParser::STR: {
        setState(109);
        externFuncHeader();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(112);
    match(WPLParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureContext ------------------------------------------------------------------

WPLParser::ProcedureContext::ProcedureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::ProcHeaderContext* WPLParser::ProcedureContext::procHeader() {
  return getRuleContext<WPLParser::ProcHeaderContext>(0);
}

WPLParser::BlockContext* WPLParser::ProcedureContext::block() {
  return getRuleContext<WPLParser::BlockContext>(0);
}


size_t WPLParser::ProcedureContext::getRuleIndex() const {
  return WPLParser::RuleProcedure;
}

void WPLParser::ProcedureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedure(this);
}

void WPLParser::ProcedureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedure(this);
}


std::any WPLParser::ProcedureContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitProcedure(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ProcedureContext* WPLParser::procedure() {
  ProcedureContext *_localctx = _tracker.createInstance<ProcedureContext>(_ctx, getState());
  enterRule(_localctx, 18, WPLParser::RuleProcedure);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(114);
    procHeader();
    setState(115);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcHeaderContext ------------------------------------------------------------------

WPLParser::ProcHeaderContext::ProcHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ProcHeaderContext::PROC() {
  return getToken(WPLParser::PROC, 0);
}

tree::TerminalNode* WPLParser::ProcHeaderContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::ProcHeaderContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

tree::TerminalNode* WPLParser::ProcHeaderContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ParamsContext* WPLParser::ProcHeaderContext::params() {
  return getRuleContext<WPLParser::ParamsContext>(0);
}


size_t WPLParser::ProcHeaderContext::getRuleIndex() const {
  return WPLParser::RuleProcHeader;
}

void WPLParser::ProcHeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcHeader(this);
}

void WPLParser::ProcHeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcHeader(this);
}


std::any WPLParser::ProcHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitProcHeader(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ProcHeaderContext* WPLParser::procHeader() {
  ProcHeaderContext *_localctx = _tracker.createInstance<ProcHeaderContext>(_ctx, getState());
  enterRule(_localctx, 20, WPLParser::RuleProcHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    match(WPLParser::PROC);
    setState(118);
    antlrcpp::downCast<ProcHeaderContext *>(_localctx)->id = match(WPLParser::ID);
    setState(119);
    match(WPLParser::LPAR);
    setState(121);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
      | (1ULL << WPLParser::INT)
      | (1ULL << WPLParser::STR))) != 0)) {
      setState(120);
      antlrcpp::downCast<ProcHeaderContext *>(_localctx)->p = params();
    }
    setState(123);
    match(WPLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternProcHeaderContext ------------------------------------------------------------------

WPLParser::ExternProcHeaderContext::ExternProcHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::PROC() {
  return getToken(WPLParser::PROC, 0);
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ParamsContext* WPLParser::ExternProcHeaderContext::params() {
  return getRuleContext<WPLParser::ParamsContext>(0);
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::COMMA() {
  return getToken(WPLParser::COMMA, 0);
}

tree::TerminalNode* WPLParser::ExternProcHeaderContext::ELLIPSIS() {
  return getToken(WPLParser::ELLIPSIS, 0);
}


size_t WPLParser::ExternProcHeaderContext::getRuleIndex() const {
  return WPLParser::RuleExternProcHeader;
}

void WPLParser::ExternProcHeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternProcHeader(this);
}

void WPLParser::ExternProcHeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternProcHeader(this);
}


std::any WPLParser::ExternProcHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitExternProcHeader(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ExternProcHeaderContext* WPLParser::externProcHeader() {
  ExternProcHeaderContext *_localctx = _tracker.createInstance<ExternProcHeaderContext>(_ctx, getState());
  enterRule(_localctx, 22, WPLParser::RuleExternProcHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    match(WPLParser::PROC);
    setState(126);
    antlrcpp::downCast<ExternProcHeaderContext *>(_localctx)->id = match(WPLParser::ID);
    setState(127);
    match(WPLParser::LPAR);
    setState(138);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(128);
      params();
      setState(129);
      match(WPLParser::COMMA);
      setState(130);
      match(WPLParser::ELLIPSIS);
      break;
    }

    case 2: {
      setState(133);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
        | (1ULL << WPLParser::INT)
        | (1ULL << WPLParser::STR))) != 0)) {
        setState(132);
        params();
      }
      break;
    }

    case 3: {
      setState(136);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WPLParser::ELLIPSIS) {
        setState(135);
        match(WPLParser::ELLIPSIS);
      }
      break;
    }

    default:
      break;
    }
    setState(140);
    match(WPLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

WPLParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::FuncHeaderContext* WPLParser::FunctionContext::funcHeader() {
  return getRuleContext<WPLParser::FuncHeaderContext>(0);
}

WPLParser::BlockContext* WPLParser::FunctionContext::block() {
  return getRuleContext<WPLParser::BlockContext>(0);
}


size_t WPLParser::FunctionContext::getRuleIndex() const {
  return WPLParser::RuleFunction;
}

void WPLParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void WPLParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any WPLParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::FunctionContext* WPLParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 24, WPLParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(142);
    funcHeader();
    setState(143);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncHeaderContext ------------------------------------------------------------------

WPLParser::FuncHeaderContext::FuncHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::FuncHeaderContext::FUNC() {
  return getToken(WPLParser::FUNC, 0);
}

tree::TerminalNode* WPLParser::FuncHeaderContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::FuncHeaderContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

WPLParser::TypeContext* WPLParser::FuncHeaderContext::type() {
  return getRuleContext<WPLParser::TypeContext>(0);
}

tree::TerminalNode* WPLParser::FuncHeaderContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ParamsContext* WPLParser::FuncHeaderContext::params() {
  return getRuleContext<WPLParser::ParamsContext>(0);
}


size_t WPLParser::FuncHeaderContext::getRuleIndex() const {
  return WPLParser::RuleFuncHeader;
}

void WPLParser::FuncHeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncHeader(this);
}

void WPLParser::FuncHeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncHeader(this);
}


std::any WPLParser::FuncHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitFuncHeader(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::FuncHeaderContext* WPLParser::funcHeader() {
  FuncHeaderContext *_localctx = _tracker.createInstance<FuncHeaderContext>(_ctx, getState());
  enterRule(_localctx, 26, WPLParser::RuleFuncHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(145);
    antlrcpp::downCast<FuncHeaderContext *>(_localctx)->t = type();
    setState(146);
    match(WPLParser::FUNC);
    setState(147);
    antlrcpp::downCast<FuncHeaderContext *>(_localctx)->id = match(WPLParser::ID);
    setState(148);
    match(WPLParser::LPAR);
    setState(150);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
      | (1ULL << WPLParser::INT)
      | (1ULL << WPLParser::STR))) != 0)) {
      setState(149);
      antlrcpp::downCast<FuncHeaderContext *>(_localctx)->p = params();
    }
    setState(152);
    match(WPLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternFuncHeaderContext ------------------------------------------------------------------

WPLParser::ExternFuncHeaderContext::ExternFuncHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::FUNC() {
  return getToken(WPLParser::FUNC, 0);
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

WPLParser::TypeContext* WPLParser::ExternFuncHeaderContext::type() {
  return getRuleContext<WPLParser::TypeContext>(0);
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ParamsContext* WPLParser::ExternFuncHeaderContext::params() {
  return getRuleContext<WPLParser::ParamsContext>(0);
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::COMMA() {
  return getToken(WPLParser::COMMA, 0);
}

tree::TerminalNode* WPLParser::ExternFuncHeaderContext::ELLIPSIS() {
  return getToken(WPLParser::ELLIPSIS, 0);
}


size_t WPLParser::ExternFuncHeaderContext::getRuleIndex() const {
  return WPLParser::RuleExternFuncHeader;
}

void WPLParser::ExternFuncHeaderContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternFuncHeader(this);
}

void WPLParser::ExternFuncHeaderContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternFuncHeader(this);
}


std::any WPLParser::ExternFuncHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitExternFuncHeader(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ExternFuncHeaderContext* WPLParser::externFuncHeader() {
  ExternFuncHeaderContext *_localctx = _tracker.createInstance<ExternFuncHeaderContext>(_ctx, getState());
  enterRule(_localctx, 28, WPLParser::RuleExternFuncHeader);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    antlrcpp::downCast<ExternFuncHeaderContext *>(_localctx)->t = type();
    setState(155);
    match(WPLParser::FUNC);
    setState(156);
    antlrcpp::downCast<ExternFuncHeaderContext *>(_localctx)->id = match(WPLParser::ID);
    setState(157);
    match(WPLParser::LPAR);
    setState(168);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(158);
      params();
      setState(159);
      match(WPLParser::COMMA);
      setState(160);
      match(WPLParser::ELLIPSIS);
      break;
    }

    case 2: {
      setState(163);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
        | (1ULL << WPLParser::INT)
        | (1ULL << WPLParser::STR))) != 0)) {
        setState(162);
        params();
      }
      break;
    }

    case 3: {
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == WPLParser::ELLIPSIS) {
        setState(165);
        match(WPLParser::ELLIPSIS);
      }
      break;
    }

    default:
      break;
    }
    setState(170);
    match(WPLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamsContext ------------------------------------------------------------------

WPLParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WPLParser::TypeContext *> WPLParser::ParamsContext::type() {
  return getRuleContexts<WPLParser::TypeContext>();
}

WPLParser::TypeContext* WPLParser::ParamsContext::type(size_t i) {
  return getRuleContext<WPLParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> WPLParser::ParamsContext::ID() {
  return getTokens(WPLParser::ID);
}

tree::TerminalNode* WPLParser::ParamsContext::ID(size_t i) {
  return getToken(WPLParser::ID, i);
}

std::vector<tree::TerminalNode *> WPLParser::ParamsContext::COMMA() {
  return getTokens(WPLParser::COMMA);
}

tree::TerminalNode* WPLParser::ParamsContext::COMMA(size_t i) {
  return getToken(WPLParser::COMMA, i);
}


size_t WPLParser::ParamsContext::getRuleIndex() const {
  return WPLParser::RuleParams;
}

void WPLParser::ParamsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParams(this);
}

void WPLParser::ParamsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParams(this);
}


std::any WPLParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ParamsContext* WPLParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 30, WPLParser::RuleParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(172);
    type();
    setState(173);
    match(WPLParser::ID);
    setState(180);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(174);
        match(WPLParser::COMMA);
        setState(175);
        type();
        setState(176);
        match(WPLParser::ID); 
      }
      setState(182);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

WPLParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::BlockContext::LBRACE() {
  return getToken(WPLParser::LBRACE, 0);
}

tree::TerminalNode* WPLParser::BlockContext::RBRACE() {
  return getToken(WPLParser::RBRACE, 0);
}

std::vector<WPLParser::StatementContext *> WPLParser::BlockContext::statement() {
  return getRuleContexts<WPLParser::StatementContext>();
}

WPLParser::StatementContext* WPLParser::BlockContext::statement(size_t i) {
  return getRuleContext<WPLParser::StatementContext>(i);
}

std::vector<WPLParser::VarDeclarationContext *> WPLParser::BlockContext::varDeclaration() {
  return getRuleContexts<WPLParser::VarDeclarationContext>();
}

WPLParser::VarDeclarationContext* WPLParser::BlockContext::varDeclaration(size_t i) {
  return getRuleContext<WPLParser::VarDeclarationContext>(i);
}

std::vector<WPLParser::BlockContext *> WPLParser::BlockContext::block() {
  return getRuleContexts<WPLParser::BlockContext>();
}

WPLParser::BlockContext* WPLParser::BlockContext::block(size_t i) {
  return getRuleContext<WPLParser::BlockContext>(i);
}


size_t WPLParser::BlockContext::getRuleIndex() const {
  return WPLParser::RuleBlock;
}

void WPLParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void WPLParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any WPLParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::BlockContext* WPLParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 32, WPLParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(183);
    match(WPLParser::LBRACE);
    setState(187); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(187);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(184);
        statement();
        break;
      }

      case 2: {
        setState(185);
        varDeclaration();
        break;
      }

      case 3: {
        setState(186);
        block();
        break;
      }

      default:
        break;
      }
      setState(189); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::BOOL)
      | (1ULL << WPLParser::INT)
      | (1ULL << WPLParser::STR)
      | (1ULL << WPLParser::VAR)
      | (1ULL << WPLParser::RETURN)
      | (1ULL << WPLParser::WHILE)
      | (1ULL << WPLParser::SELECT)
      | (1ULL << WPLParser::IF)
      | (1ULL << WPLParser::LBRACE)
      | (1ULL << WPLParser::ID))) != 0));
    setState(191);
    match(WPLParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

WPLParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::AssignmentContext* WPLParser::StatementContext::assignment() {
  return getRuleContext<WPLParser::AssignmentContext>(0);
}

WPLParser::LoopContext* WPLParser::StatementContext::loop() {
  return getRuleContext<WPLParser::LoopContext>(0);
}

WPLParser::SelectContext* WPLParser::StatementContext::select() {
  return getRuleContext<WPLParser::SelectContext>(0);
}

WPLParser::ConditionalContext* WPLParser::StatementContext::conditional() {
  return getRuleContext<WPLParser::ConditionalContext>(0);
}

WPLParser::CallContext* WPLParser::StatementContext::call() {
  return getRuleContext<WPLParser::CallContext>(0);
}

tree::TerminalNode* WPLParser::StatementContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

WPLParser::BlockContext* WPLParser::StatementContext::block() {
  return getRuleContext<WPLParser::BlockContext>(0);
}

WPLParser::ReturnContext* WPLParser::StatementContext::return_() {
  return getRuleContext<WPLParser::ReturnContext>(0);
}


size_t WPLParser::StatementContext::getRuleIndex() const {
  return WPLParser::RuleStatement;
}

void WPLParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void WPLParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


std::any WPLParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::StatementContext* WPLParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 34, WPLParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(202);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(193);
      assignment();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(194);
      loop();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(195);
      select();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(196);
      conditional();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(197);
      call();
      setState(198);
      match(WPLParser::SEMICOLON);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(200);
      block();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(201);
      return_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopContext ------------------------------------------------------------------

WPLParser::LoopContext::LoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::LoopContext::WHILE() {
  return getToken(WPLParser::WHILE, 0);
}

WPLParser::BlockContext* WPLParser::LoopContext::block() {
  return getRuleContext<WPLParser::BlockContext>(0);
}

WPLParser::ExprContext* WPLParser::LoopContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}


size_t WPLParser::LoopContext::getRuleIndex() const {
  return WPLParser::RuleLoop;
}

void WPLParser::LoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoop(this);
}

void WPLParser::LoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoop(this);
}


std::any WPLParser::LoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitLoop(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::LoopContext* WPLParser::loop() {
  LoopContext *_localctx = _tracker.createInstance<LoopContext>(_ctx, getState());
  enterRule(_localctx, 36, WPLParser::RuleLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(WPLParser::WHILE);
    setState(205);
    antlrcpp::downCast<LoopContext *>(_localctx)->e = expr(0);
    setState(206);
    match(WPLParser::T__0);
    setState(207);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalContext ------------------------------------------------------------------

WPLParser::ConditionalContext::ConditionalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ConditionalContext::IF() {
  return getToken(WPLParser::IF, 0);
}

std::vector<WPLParser::BlockContext *> WPLParser::ConditionalContext::block() {
  return getRuleContexts<WPLParser::BlockContext>();
}

WPLParser::BlockContext* WPLParser::ConditionalContext::block(size_t i) {
  return getRuleContext<WPLParser::BlockContext>(i);
}

WPLParser::ExprContext* WPLParser::ConditionalContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

tree::TerminalNode* WPLParser::ConditionalContext::THEN() {
  return getToken(WPLParser::THEN, 0);
}

tree::TerminalNode* WPLParser::ConditionalContext::ELSE() {
  return getToken(WPLParser::ELSE, 0);
}


size_t WPLParser::ConditionalContext::getRuleIndex() const {
  return WPLParser::RuleConditional;
}

void WPLParser::ConditionalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditional(this);
}

void WPLParser::ConditionalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditional(this);
}


std::any WPLParser::ConditionalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitConditional(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ConditionalContext* WPLParser::conditional() {
  ConditionalContext *_localctx = _tracker.createInstance<ConditionalContext>(_ctx, getState());
  enterRule(_localctx, 38, WPLParser::RuleConditional);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(WPLParser::IF);
    setState(210);
    antlrcpp::downCast<ConditionalContext *>(_localctx)->e = expr(0);
    setState(212);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WPLParser::THEN) {
      setState(211);
      match(WPLParser::THEN);
    }
    setState(214);
    block();
    setState(217);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == WPLParser::ELSE) {
      setState(215);
      match(WPLParser::ELSE);
      setState(216);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectContext ------------------------------------------------------------------

WPLParser::SelectContext::SelectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::SelectContext::SELECT() {
  return getToken(WPLParser::SELECT, 0);
}

tree::TerminalNode* WPLParser::SelectContext::LBRACE() {
  return getToken(WPLParser::LBRACE, 0);
}

tree::TerminalNode* WPLParser::SelectContext::RBRACE() {
  return getToken(WPLParser::RBRACE, 0);
}

std::vector<WPLParser::SelectAltContext *> WPLParser::SelectContext::selectAlt() {
  return getRuleContexts<WPLParser::SelectAltContext>();
}

WPLParser::SelectAltContext* WPLParser::SelectContext::selectAlt(size_t i) {
  return getRuleContext<WPLParser::SelectAltContext>(i);
}


size_t WPLParser::SelectContext::getRuleIndex() const {
  return WPLParser::RuleSelect;
}

void WPLParser::SelectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect(this);
}

void WPLParser::SelectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect(this);
}


std::any WPLParser::SelectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitSelect(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::SelectContext* WPLParser::select() {
  SelectContext *_localctx = _tracker.createInstance<SelectContext>(_ctx, getState());
  enterRule(_localctx, 40, WPLParser::RuleSelect);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(219);
    match(WPLParser::SELECT);
    setState(220);
    match(WPLParser::LBRACE);
    setState(222); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(221);
      selectAlt();
      setState(224); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::MINUS)
      | (1ULL << WPLParser::NOT)
      | (1ULL << WPLParser::LPAR)
      | (1ULL << WPLParser::INTEGER)
      | (1ULL << WPLParser::BOOLEAN)
      | (1ULL << WPLParser::ID)
      | (1ULL << WPLParser::STRING))) != 0));
    setState(226);
    match(WPLParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectAltContext ------------------------------------------------------------------

WPLParser::SelectAltContext::SelectAltContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

WPLParser::ExprContext* WPLParser::SelectAltContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

WPLParser::StatementContext* WPLParser::SelectAltContext::statement() {
  return getRuleContext<WPLParser::StatementContext>(0);
}


size_t WPLParser::SelectAltContext::getRuleIndex() const {
  return WPLParser::RuleSelectAlt;
}

void WPLParser::SelectAltContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectAlt(this);
}

void WPLParser::SelectAltContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectAlt(this);
}


std::any WPLParser::SelectAltContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitSelectAlt(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::SelectAltContext* WPLParser::selectAlt() {
  SelectAltContext *_localctx = _tracker.createInstance<SelectAltContext>(_ctx, getState());
  enterRule(_localctx, 42, WPLParser::RuleSelectAlt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    antlrcpp::downCast<SelectAltContext *>(_localctx)->e = expr(0);
    setState(229);
    match(WPLParser::T__1);
    setState(230);
    antlrcpp::downCast<SelectAltContext *>(_localctx)->s = statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallContext ------------------------------------------------------------------

WPLParser::CallContext::CallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::CallContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::CallContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

tree::TerminalNode* WPLParser::CallContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ArgumentsContext* WPLParser::CallContext::arguments() {
  return getRuleContext<WPLParser::ArgumentsContext>(0);
}


size_t WPLParser::CallContext::getRuleIndex() const {
  return WPLParser::RuleCall;
}

void WPLParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}

void WPLParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}


std::any WPLParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::CallContext* WPLParser::call() {
  CallContext *_localctx = _tracker.createInstance<CallContext>(_ctx, getState());
  enterRule(_localctx, 44, WPLParser::RuleCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    antlrcpp::downCast<CallContext *>(_localctx)->id = match(WPLParser::ID);
    setState(233);
    match(WPLParser::LPAR);
    setState(235);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::INTEGER)
      | (1ULL << WPLParser::BOOLEAN)
      | (1ULL << WPLParser::ID)
      | (1ULL << WPLParser::STRING))) != 0)) {
      setState(234);
      arguments();
    }
    setState(237);
    match(WPLParser::RPAR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

WPLParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<WPLParser::ArgContext *> WPLParser::ArgumentsContext::arg() {
  return getRuleContexts<WPLParser::ArgContext>();
}

WPLParser::ArgContext* WPLParser::ArgumentsContext::arg(size_t i) {
  return getRuleContext<WPLParser::ArgContext>(i);
}

std::vector<tree::TerminalNode *> WPLParser::ArgumentsContext::COMMA() {
  return getTokens(WPLParser::COMMA);
}

tree::TerminalNode* WPLParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(WPLParser::COMMA, i);
}


size_t WPLParser::ArgumentsContext::getRuleIndex() const {
  return WPLParser::RuleArguments;
}

void WPLParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void WPLParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


std::any WPLParser::ArgumentsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitArguments(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ArgumentsContext* WPLParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 46, WPLParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    arg();
    setState(244);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == WPLParser::COMMA) {
      setState(240);
      match(WPLParser::COMMA);
      setState(241);
      arg();
      setState(246);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

WPLParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ArgContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ConstantContext* WPLParser::ArgContext::constant() {
  return getRuleContext<WPLParser::ConstantContext>(0);
}


size_t WPLParser::ArgContext::getRuleIndex() const {
  return WPLParser::RuleArg;
}

void WPLParser::ArgContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArg(this);
}

void WPLParser::ArgContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArg(this);
}


std::any WPLParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ArgContext* WPLParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 48, WPLParser::RuleArg);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case WPLParser::ID: {
        setState(247);
        antlrcpp::downCast<ArgContext *>(_localctx)->id = match(WPLParser::ID);
        break;
      }

      case WPLParser::INTEGER:
      case WPLParser::BOOLEAN:
      case WPLParser::STRING: {
        setState(248);
        antlrcpp::downCast<ArgContext *>(_localctx)->c = constant();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

WPLParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ReturnContext::RETURN() {
  return getToken(WPLParser::RETURN, 0);
}

tree::TerminalNode* WPLParser::ReturnContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

WPLParser::ExprContext* WPLParser::ReturnContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}


size_t WPLParser::ReturnContext::getRuleIndex() const {
  return WPLParser::RuleReturn;
}

void WPLParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void WPLParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any WPLParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ReturnContext* WPLParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 50, WPLParser::RuleReturn);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(251);
    match(WPLParser::RETURN);
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::MINUS)
      | (1ULL << WPLParser::NOT)
      | (1ULL << WPLParser::LPAR)
      | (1ULL << WPLParser::INTEGER)
      | (1ULL << WPLParser::BOOLEAN)
      | (1ULL << WPLParser::ID)
      | (1ULL << WPLParser::STRING))) != 0)) {
      setState(252);
      expr(0);
    }
    setState(255);
    match(WPLParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantContext ------------------------------------------------------------------

WPLParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ConstantContext::INTEGER() {
  return getToken(WPLParser::INTEGER, 0);
}

tree::TerminalNode* WPLParser::ConstantContext::STRING() {
  return getToken(WPLParser::STRING, 0);
}

tree::TerminalNode* WPLParser::ConstantContext::BOOLEAN() {
  return getToken(WPLParser::BOOLEAN, 0);
}


size_t WPLParser::ConstantContext::getRuleIndex() const {
  return WPLParser::RuleConstant;
}

void WPLParser::ConstantContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstant(this);
}

void WPLParser::ConstantContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstant(this);
}


std::any WPLParser::ConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitConstant(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ConstantContext* WPLParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 52, WPLParser::RuleConstant);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << WPLParser::INTEGER)
      | (1ULL << WPLParser::BOOLEAN)
      | (1ULL << WPLParser::STRING))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

WPLParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::AssignmentContext::ASSIGN() {
  return getToken(WPLParser::ASSIGN, 0);
}

tree::TerminalNode* WPLParser::AssignmentContext::SEMICOLON() {
  return getToken(WPLParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> WPLParser::AssignmentContext::ID() {
  return getTokens(WPLParser::ID);
}

tree::TerminalNode* WPLParser::AssignmentContext::ID(size_t i) {
  return getToken(WPLParser::ID, i);
}

std::vector<WPLParser::ExprContext *> WPLParser::AssignmentContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::AssignmentContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> WPLParser::AssignmentContext::COMMA() {
  return getTokens(WPLParser::COMMA);
}

tree::TerminalNode* WPLParser::AssignmentContext::COMMA(size_t i) {
  return getToken(WPLParser::COMMA, i);
}

WPLParser::ArrayIndexContext* WPLParser::AssignmentContext::arrayIndex() {
  return getRuleContext<WPLParser::ArrayIndexContext>(0);
}


size_t WPLParser::AssignmentContext::getRuleIndex() const {
  return WPLParser::RuleAssignment;
}

void WPLParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void WPLParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}


std::any WPLParser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::AssignmentContext* WPLParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 54, WPLParser::RuleAssignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(259);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->idToken = match(WPLParser::ID);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->targets.push_back(antlrcpp::downCast<AssignmentContext *>(_localctx)->idToken);
      setState(264);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WPLParser::COMMA) {
        setState(260);
        match(WPLParser::COMMA);
        setState(261);
        antlrcpp::downCast<AssignmentContext *>(_localctx)->idToken = match(WPLParser::ID);
        antlrcpp::downCast<AssignmentContext *>(_localctx)->targets.push_back(antlrcpp::downCast<AssignmentContext *>(_localctx)->idToken);
        setState(266);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(267);
      match(WPLParser::ASSIGN);
      setState(268);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->exprs.push_back(antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext);
      setState(273);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == WPLParser::COMMA) {
        setState(269);
        match(WPLParser::COMMA);
        setState(270);
        antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext = expr(0);
        antlrcpp::downCast<AssignmentContext *>(_localctx)->exprs.push_back(antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext);
        setState(275);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(276);
      match(WPLParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(278);
      arrayIndex();
      setState(279);
      match(WPLParser::ASSIGN);
      setState(280);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext = expr(0);
      antlrcpp::downCast<AssignmentContext *>(_localctx)->e.push_back(antlrcpp::downCast<AssignmentContext *>(_localctx)->exprContext);
      setState(281);
      match(WPLParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayIndexContext ------------------------------------------------------------------

WPLParser::ArrayIndexContext::ArrayIndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* WPLParser::ArrayIndexContext::LBRACKET() {
  return getToken(WPLParser::LBRACKET, 0);
}

WPLParser::ExprContext* WPLParser::ArrayIndexContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

tree::TerminalNode* WPLParser::ArrayIndexContext::RBRACKET() {
  return getToken(WPLParser::RBRACKET, 0);
}

tree::TerminalNode* WPLParser::ArrayIndexContext::ID() {
  return getToken(WPLParser::ID, 0);
}


size_t WPLParser::ArrayIndexContext::getRuleIndex() const {
  return WPLParser::RuleArrayIndex;
}

void WPLParser::ArrayIndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayIndex(this);
}

void WPLParser::ArrayIndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayIndex(this);
}


std::any WPLParser::ArrayIndexContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitArrayIndex(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ArrayIndexContext* WPLParser::arrayIndex() {
  ArrayIndexContext *_localctx = _tracker.createInstance<ArrayIndexContext>(_ctx, getState());
  enterRule(_localctx, 56, WPLParser::RuleArrayIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(285);
    antlrcpp::downCast<ArrayIndexContext *>(_localctx)->id = match(WPLParser::ID);
    setState(286);
    match(WPLParser::LBRACKET);
    setState(287);
    expr(0);
    setState(288);
    match(WPLParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

WPLParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t WPLParser::ExprContext::getRuleIndex() const {
  return WPLParser::RuleExpr;
}

void WPLParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- AndExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::AndExprContext::AND() {
  return getToken(WPLParser::AND, 0);
}

std::vector<WPLParser::ExprContext *> WPLParser::AndExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::AndExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

WPLParser::AndExprContext::AndExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void WPLParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any WPLParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::IDExprContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::IDExprContext::IDExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::IDExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIDExpr(this);
}
void WPLParser::IDExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIDExpr(this);
}

std::any WPLParser::IDExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitIDExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstExprContext ------------------------------------------------------------------

WPLParser::ConstantContext* WPLParser::ConstExprContext::constant() {
  return getRuleContext<WPLParser::ConstantContext>(0);
}

WPLParser::ConstExprContext::ConstExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::ConstExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstExpr(this);
}
void WPLParser::ConstExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstExpr(this);
}

std::any WPLParser::ConstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitConstExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SubscriptExprContext ------------------------------------------------------------------

WPLParser::ArrayIndexContext* WPLParser::SubscriptExprContext::arrayIndex() {
  return getRuleContext<WPLParser::ArrayIndexContext>(0);
}

WPLParser::SubscriptExprContext::SubscriptExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::SubscriptExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubscriptExpr(this);
}
void WPLParser::SubscriptExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubscriptExpr(this);
}

std::any WPLParser::SubscriptExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitSubscriptExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RelExprContext ------------------------------------------------------------------

std::vector<WPLParser::ExprContext *> WPLParser::RelExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::RelExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

tree::TerminalNode* WPLParser::RelExprContext::LESS() {
  return getToken(WPLParser::LESS, 0);
}

tree::TerminalNode* WPLParser::RelExprContext::LEQ() {
  return getToken(WPLParser::LEQ, 0);
}

tree::TerminalNode* WPLParser::RelExprContext::GTR() {
  return getToken(WPLParser::GTR, 0);
}

tree::TerminalNode* WPLParser::RelExprContext::GEQ() {
  return getToken(WPLParser::GEQ, 0);
}

WPLParser::RelExprContext::RelExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::RelExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelExpr(this);
}
void WPLParser::RelExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelExpr(this);
}

std::any WPLParser::RelExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitRelExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultExprContext ------------------------------------------------------------------

std::vector<WPLParser::ExprContext *> WPLParser::MultExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::MultExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

tree::TerminalNode* WPLParser::MultExprContext::MUL() {
  return getToken(WPLParser::MUL, 0);
}

tree::TerminalNode* WPLParser::MultExprContext::DIV() {
  return getToken(WPLParser::DIV, 0);
}

WPLParser::MultExprContext::MultExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::MultExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultExpr(this);
}
void WPLParser::MultExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultExpr(this);
}

std::any WPLParser::MultExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitMultExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddExprContext ------------------------------------------------------------------

std::vector<WPLParser::ExprContext *> WPLParser::AddExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::AddExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

tree::TerminalNode* WPLParser::AddExprContext::PLUS() {
  return getToken(WPLParser::PLUS, 0);
}

tree::TerminalNode* WPLParser::AddExprContext::MINUS() {
  return getToken(WPLParser::MINUS, 0);
}

WPLParser::AddExprContext::AddExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::AddExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddExpr(this);
}
void WPLParser::AddExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddExpr(this);
}

std::any WPLParser::AddExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitAddExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayLengthExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::ArrayLengthExprContext::DOT() {
  return getToken(WPLParser::DOT, 0);
}

tree::TerminalNode* WPLParser::ArrayLengthExprContext::LENGTH() {
  return getToken(WPLParser::LENGTH, 0);
}

tree::TerminalNode* WPLParser::ArrayLengthExprContext::ID() {
  return getToken(WPLParser::ID, 0);
}

WPLParser::ArrayLengthExprContext::ArrayLengthExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::ArrayLengthExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLengthExpr(this);
}
void WPLParser::ArrayLengthExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLengthExpr(this);
}

std::any WPLParser::ArrayLengthExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitArrayLengthExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UMinusExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::UMinusExprContext::MINUS() {
  return getToken(WPLParser::MINUS, 0);
}

WPLParser::ExprContext* WPLParser::UMinusExprContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

WPLParser::UMinusExprContext::UMinusExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::UMinusExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUMinusExpr(this);
}
void WPLParser::UMinusExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUMinusExpr(this);
}

std::any WPLParser::UMinusExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitUMinusExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::OrExprContext::OR() {
  return getToken(WPLParser::OR, 0);
}

std::vector<WPLParser::ExprContext *> WPLParser::OrExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::OrExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

WPLParser::OrExprContext::OrExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void WPLParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any WPLParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqExprContext ------------------------------------------------------------------

std::vector<WPLParser::ExprContext *> WPLParser::EqExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::EqExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

tree::TerminalNode* WPLParser::EqExprContext::EQUAL() {
  return getToken(WPLParser::EQUAL, 0);
}

tree::TerminalNode* WPLParser::EqExprContext::NEQ() {
  return getToken(WPLParser::NEQ, 0);
}

WPLParser::EqExprContext::EqExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::EqExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqExpr(this);
}
void WPLParser::EqExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqExpr(this);
}

std::any WPLParser::EqExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitEqExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncProcCallExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::FuncProcCallExprContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

tree::TerminalNode* WPLParser::FuncProcCallExprContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

tree::TerminalNode* WPLParser::FuncProcCallExprContext::ID() {
  return getToken(WPLParser::ID, 0);
}

std::vector<WPLParser::ExprContext *> WPLParser::FuncProcCallExprContext::expr() {
  return getRuleContexts<WPLParser::ExprContext>();
}

WPLParser::ExprContext* WPLParser::FuncProcCallExprContext::expr(size_t i) {
  return getRuleContext<WPLParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> WPLParser::FuncProcCallExprContext::COMMA() {
  return getTokens(WPLParser::COMMA);
}

tree::TerminalNode* WPLParser::FuncProcCallExprContext::COMMA(size_t i) {
  return getToken(WPLParser::COMMA, i);
}

WPLParser::FuncProcCallExprContext::FuncProcCallExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::FuncProcCallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFuncProcCallExpr(this);
}
void WPLParser::FuncProcCallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFuncProcCallExpr(this);
}

std::any WPLParser::FuncProcCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitFuncProcCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::NotExprContext::NOT() {
  return getToken(WPLParser::NOT, 0);
}

WPLParser::ExprContext* WPLParser::NotExprContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

WPLParser::NotExprContext::NotExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::NotExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotExpr(this);
}
void WPLParser::NotExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotExpr(this);
}

std::any WPLParser::NotExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitNotExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExprContext ------------------------------------------------------------------

tree::TerminalNode* WPLParser::ParenExprContext::LPAR() {
  return getToken(WPLParser::LPAR, 0);
}

WPLParser::ExprContext* WPLParser::ParenExprContext::expr() {
  return getRuleContext<WPLParser::ExprContext>(0);
}

tree::TerminalNode* WPLParser::ParenExprContext::RPAR() {
  return getToken(WPLParser::RPAR, 0);
}

WPLParser::ParenExprContext::ParenExprContext(ExprContext *ctx) { copyFrom(ctx); }

void WPLParser::ParenExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParenExpr(this);
}
void WPLParser::ParenExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<WPLListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParenExpr(this);
}

std::any WPLParser::ParenExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<WPLVisitor*>(visitor))
    return parserVisitor->visitParenExpr(this);
  else
    return visitor->visitChildren(this);
}

WPLParser::ExprContext* WPLParser::expr() {
   return expr(0);
}

WPLParser::ExprContext* WPLParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  WPLParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  WPLParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 58;
  enterRecursionRule(_localctx, 58, WPLParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(318);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<FuncProcCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(291);
      antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->fpname = match(WPLParser::ID);
      setState(292);
      match(WPLParser::LPAR);
      setState(301);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << WPLParser::MINUS)
        | (1ULL << WPLParser::NOT)
        | (1ULL << WPLParser::LPAR)
        | (1ULL << WPLParser::INTEGER)
        | (1ULL << WPLParser::BOOLEAN)
        | (1ULL << WPLParser::ID)
        | (1ULL << WPLParser::STRING))) != 0)) {
        setState(293);
        antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->exprContext = expr(0);
        antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->args.push_back(antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->exprContext);
        setState(298);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == WPLParser::COMMA) {
          setState(294);
          match(WPLParser::COMMA);
          setState(295);
          antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->exprContext = expr(0);
          antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->args.push_back(antlrcpp::downCast<FuncProcCallExprContext *>(_localctx)->exprContext);
          setState(300);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(303);
      match(WPLParser::RPAR);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<SubscriptExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(304);
      arrayIndex();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UMinusExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(305);
      match(WPLParser::MINUS);
      setState(306);
      expr(12);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NotExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(307);
      match(WPLParser::NOT);
      setState(308);
      expr(11);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ParenExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(309);
      match(WPLParser::LPAR);
      setState(310);
      expr(0);
      setState(311);
      match(WPLParser::RPAR);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<ArrayLengthExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(313);
      antlrcpp::downCast<ArrayLengthExprContext *>(_localctx)->arrayname = match(WPLParser::ID);
      setState(314);
      match(WPLParser::DOT);
      setState(315);
      match(WPLParser::LENGTH);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<IDExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(316);
      match(WPLParser::ID);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<ConstExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(317);
      constant();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(340);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(338);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(320);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(321);
          _la = _input->LA(1);
          if (!(_la == WPLParser::DIV

          || _la == WPLParser::MUL)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(322);
          antlrcpp::downCast<MultExprContext *>(_localctx)->right = expr(11);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(323);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(324);
          _la = _input->LA(1);
          if (!(_la == WPLParser::MINUS

          || _la == WPLParser::PLUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(325);
          antlrcpp::downCast<AddExprContext *>(_localctx)->right = expr(10);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(326);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(327);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << WPLParser::GEQ)
            | (1ULL << WPLParser::GTR)
            | (1ULL << WPLParser::LEQ)
            | (1ULL << WPLParser::LESS))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(328);
          antlrcpp::downCast<RelExprContext *>(_localctx)->right = expr(9);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<EqExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(329);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(330);
          _la = _input->LA(1);
          if (!(_la == WPLParser::EQUAL

          || _la == WPLParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(331);
          antlrcpp::downCast<EqExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(332);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(333);
          match(WPLParser::AND);
          setState(334);
          antlrcpp::downCast<AndExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(335);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(336);
          match(WPLParser::OR);
          setState(337);
          antlrcpp::downCast<OrExprContext *>(_localctx)->right = expr(6);
          break;
        }

        default:
          break;
        } 
      }
      setState(342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool WPLParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 29: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool WPLParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 10);
    case 1: return precpred(_ctx, 9);
    case 2: return precpred(_ctx, 8);
    case 3: return precpred(_ctx, 7);
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);

  default:
    break;
  }
  return true;
}

void WPLParser::initialize() {
  std::call_once(wplParserOnceFlag, wplParserInitialize);
}
