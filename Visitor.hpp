#ifndef _VISITOR_HPP
#define _VISITOR_HPP

class Visitor;
class Node {
public:
	virtual ~Node();
	virtual void accept(Visitor&) = 0;
};

class Expr : public Node {
public:
	void accept(Visitor&) override;
};

class Stmt : public Node {
public:
	void accept(Visitor&) override;
};

#endif
