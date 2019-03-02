#ifndef STEP_H
#define STEP_H

struct action_t;

typedef struct step_t {
  action_t* action;
  virtual void do_move() = 0;
} step_t;

struct stepLeft final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct stepRight final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

struct stepNone final : step {
  void do_move() override;
  void print(std::ostream&) const override;
};

#endif
