(*
	I pledge my honor that I have not cheated, 
	and will not cheat, on this assigment
	
	Florent Dondjeu Tschoufack
	Cosc 422 - Assignment 1
	feb 9,2021
*)


fun cardinality(nil:int list, nil:bool list) = 0
|	cardinality(L1, L2) = 
		if hd L2 then 
			1+cardinality(tl L1, tl L2)
		else cardinality(tl L1, tl L2);


fun elementOf(n:int, (nil, nil:bool list)) = false
|	elementOf(n, (L1, L2)) =
		if n = hd L1 then hd L2
		else elementOf(n, (tl L1, tl L2));


fun subset((L1:int list, L2:bool list), (M1, M2)) =
	if L1<>nil andalso M1<>nil then
		if hd L2 then
			if hd L1 = hd M1 andalso hd M2 then true
			else subset((L1, L2), (tl M1, tl M2))
		else subset((tl L1, tl L2), (M1, M2))
	else false;


(*partially works: fun doesnt check remaining elements after conditions met*)
fun equals((L1:int list, L2:bool list), (M1:int list, M2:bool list)) =
	let
		val x = cardinality(L1,L2)
		val y = cardinality(M1,M2)

		fun check(a:int list, b:bool list, x, y) =
			if a<>nil andalso x<>nil then
				if hd b then
					if hd a = hd x andalso hd y then true
					else check(a, b, tl x, tl y)
				else check(tl a, tl b, x, y)
			else false
		
		fun final(x:int, y, c1:bool, c2) =
			if x=y then
				if c1 andalso c2 then true
				else false
			else false
	in
		final(x, y, check(L1,L2,M1,M2), check(M1,M2,L1,L2))
	end;


fun union((L1:int list, L2:bool list), (M1, M2)) =
	let
		fun intList(nil:int list,[]:bool list) = []	(* creates a int list *)
		|	intList(a,b) = 
				if hd b then hd a::intList(tl a,tl b)
				else intList(tl a,tl b);

		fun boolList(nil:bool list) = []		(* creates a bool list*)
		|	boolList(y) =
				if hd y then hd(y)::boolList(tl y)
				else boolList(tl y);
		
		(* combine both lists *)
		val A1 = intList(L1,L2)@intList(M1,M2)
		val A2 = boolList(L2)@boolList(M2)
	in
		(A1,A2)
	end;


fun intersection((L1:int list, L2:bool list), (M1, M2)) = 
	let
		fun intList(nil:int list, nil:bool list) = []	(* creates an int list *)
		|	intList(a,b) = 
				if hd b then hd(a)::intList(tl a,tl b)
				else intList(tl a,tl b);
		
		val l = intList(L1,L2)
		val m = intList(M1,M2)
		
		(* creats a list with matching element*)
		fun intersect(nil:int list, nil:int list) = []:int list
		|	intersect(a,b) = 
				if b<>nil then
					if hd a = hd b then hd(a)::intersect(tl a,tl b)
					else intersect(a,tl b )
				else [];

		fun boolList(nil) = []:bool list	(* creates a bool list *)
		|	boolList(a) = true::boolList(tl a ) 

		val x = intersect(l,m)@intersect(m,l)
		val y = boolList(x)
	in
		(x,y)
	end;


fun complement((L1:int list, L2:bool list)) =
	let
		fun comp(nil:bool list) = []
		|	comp(a) = 
				if hd a then false::comp(tl a)
				else true::comp(tl a);
	in
		(L1, comp L2)
	end;


fun cartesian((L1:int list, L2:bool list), (M1, M2)) =
	let
		fun intList(nil:int list, nil:bool list) = []	(* creates an int list *)
		|	intList(a,b) = 
				if hd b then hd(a)::intList(tl a,tl b)
				else intList(tl a,tl b);
		
		val l = intList(L1,L2)
		val m = intList(M1,M2)

		fun pair(a:int, nil:int list) = []	(* helper function *)
		|	pair(a,b) = (a, hd b)::pair(a, tl b)

		fun cart(nil,b) = []	(* pairs up elments from both int list *)
		|	cart(a,b) = pair(hd a, b)@cart(tl a, b)

		val x = cart(l,m)

		fun boolList(nil) = []:bool list	(* creates a bool list *)
		|	boolList(a) = true::boolList(tl a)
	in
		(x, boolList x)
	end;
