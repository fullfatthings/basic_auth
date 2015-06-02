# Basic Auth Drupal Module

Integrates Drupal user authentication with HTTP Basic Auth, while maintaining
Drupal's flood control and user access systems.

Provides the following functionality:

* Ability to easily enable and disabled via a config setting.
* Only allow users with a certain role (via a permission) to be authenticated
  using Basic HTTP Auth.
* Allow anonymous visitors to the site.
* Prompt for authentication on access denied pages, for anonymous users.
* Dedicated & optional path to force a HTTP Authorization.
* Customize the realm message.