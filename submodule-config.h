#ifndef SUBMODULE_CONFIG_CACHE_H
#define SUBMODULE_CONFIG_CACHE_H

#include "hashmap.h"
#include "submodule.h"
#include "strbuf.h"

/*
 * Submodule entry containing the information about a certain submodule
 * in a certain revision.
 */
struct submodule {
	const char *path;
	const char *name;
	const char *url;
	int fetch_recurse;
	const char *ignore;
	const char *branch;
	struct submodule_update_strategy update_strategy;
	/* the sha1 blob id of the responsible .gitmodules file */
	unsigned char gitmodules_sha1[20];
	int recommend_shallow;
};

struct submodule_cache;
struct repository;

extern void submodule_cache_free(struct submodule_cache *cache);

extern int parse_fetch_recurse_submodules_arg(const char *opt, const char *arg);
struct option;
extern int option_fetch_parse_recurse_submodules(const struct option *opt,
						 const char *arg, int unset);
extern int parse_update_recurse_submodules_arg(const char *opt, const char *arg);
extern int parse_push_recurse_submodules_arg(const char *opt, const char *arg);
extern int parse_submodule_config_option(const char *var, const char *value);
extern int submodule_config_option(struct repository *repo,
				   const char *var, const char *value);
extern const struct submodule *submodule_from_name(
		const unsigned char *commit_or_tree, const char *name);
extern const struct submodule *submodule_from_path(
		const unsigned char *commit_or_tree, const char *path);
extern const struct submodule *submodule_from_cache(struct repository *repo,
						    const unsigned char *treeish_name,
						    const char *key);
extern int gitmodule_sha1_from_commit(const unsigned char *commit_sha1,
				      unsigned char *gitmodules_sha1,
				      struct strbuf *rev);
extern void submodule_free(void);

#endif /* SUBMODULE_CONFIG_H */
