(*
	I pledge my honor that I have not cheated, 
	and will not cheat, on this assignment
	
	Florent Dondjeu Tschoufack
	Cosc 422 - Assignment 3
	Mar 11,2021
*)

(* diML+ops types *)
datatype typ  = Bool | Int | Arrow of typ*typ; (* i.e., Arrow(argType, returnType) *) 

(* diML+ops operations *)
datatype binop = Plus | Minus | Times | Less | Conjunction | Disjunction | Equal;

(* diML+ops expressions *)
datatype expr = TrueExpr | FalseExpr | IntExpr of int 
| IfExpr of expr*expr*expr (* i.e.: IfExpr(condition, thenBranch, elseBranch) *) 
| OpExpr of expr*binop*expr | VarExpr of string | ApplyExpr of expr*expr 
| FunExpr of string*typ*typ*string*expr;
(* i.e., FunExpr(functionName, parameterType, returnType, parameterName, body) *) 

