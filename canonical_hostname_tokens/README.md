# Canonical Hostname Tokens

This module solves the problem of multiple hostnames pointing to a
single Drupal instance, where only one of those hostnames is canonical.
Regardless of the hostname in use, users may wish for token-generated
user messages to point to URLs with a defined canonical hostname.

To configure, browse to Configure → System → Canonical hostname and
set the hostname you want to be the canonical one. This hostname should
not contain any other information such as scheme, port, or path.

If the “Enforce https for all URL tokens” checkbox is checked, all
links rewritten to the canonical hostname will also use the https
scheme.