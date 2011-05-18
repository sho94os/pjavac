#ifndef FREE_H
#define FREE_H

void free_application(is_application *node);
void free_id(is_id *node);
void free_constant(is_constant *node);
void free_array_decl(is_array_decl *node);
void free_assign_op(is_assign_op *node);
void free_binary_op(is_binary_op *node);
void free_break(is_break *node);
void free_class_stmt_list(is_class_stmt_list *node);
void free_class_def(is_class_def *node);
void free_class_stmt(is_class_stmt *node);
void free_class_stmt_privacy(is_class_stmt_privacy *node);
void free_class_stmt_scope(is_class_stmt_scope *node);
void free_continue(is_continue *node);
void free_dims(is_dims *node);
void free_dims_empty_list(is_dims_empty_list* node);
void free_dims_sized(is_dims_sized *node);
void free_dims_sized_list(is_dims_sized_list *node);
void free_do_while(is_do_while *node);
void free_expr(is_expr *node);
void free_expr_list(is_expr_list *node);
void free_expr_op(is_expr_op *node);
void free_for(is_for *node);
void free_for_cond(is_for_cond *node);
void free_for_expr(is_for_expr *node);
void free_for_expr_list(is_for_expr_list *node);
void free_for_init(is_for_init *node);
void free_for_inc(is_for_inc *node);
void free_func_call(is_func_call *node);
void free_func_call_arg_list(is_func_call_arg_list *node);
void free_func_def(is_func_def *node);
void free_func_def_arg(is_func_def_arg *node);
void free_func_def_arg_list(is_func_def_arg_list *node);
void free_if(is_if *node);
void free_incr_op(is_incr_op *node);
void free_loop_stmt(is_loop_stmt *node);
void free_member_stmt(is_member_stmt *node);
void free_new_op(is_new_op *node);
void free_return(is_return *node);
void free_stmt(is_stmt *node);
void free_stmt_list(is_stmt_list *node);
void free_switch(is_switch *node);
void free_switch_stmt(is_switch_stmt *node);
void free_switch_stmt_list(is_switch_stmt_list *node);
void free_ternary_op(is_ternary_op *node);
void free_type_decl(is_type_decl *node);
void free_type_object(is_type_object *node);
void free_unary_op(is_unary_op *node);
void free_var(is_var *node);
void free_var_def(is_var_def *node);
void free_var_def_list(is_var_def_list *node);
void free_var_def_left(is_var_def_left *node);
void free_var_defs(is_var_defs *node);
void free_var_initializer(is_var_initializer *node);
void free_var_initializer_list(is_var_initializer_list *node);
void free_var_stmt(is_var_stmt *node);
void free_while(is_while *node);

#endif
