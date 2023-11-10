/**
 * @brief Convert string to an integer with checks for errors
 *
 * @param num_str to convert to integer
 * @returns non zero on error
 */
int telem_strtol(const char *num_str, char **endptr, int32_t base, int32_t *val)
{
    int ret=0;
    char *localEndPtr=NULL;

    errno = 0;  /* set to 0 so we can detect ERANGE */

    *val = strtol(num_str, &localEndPtr, base);

    if (num_str == localEndPtr)
    {
        cmsLog_error("%s NaN: \"%s\"", __FUNCTION__, num_str);
        *val = 0;
        ret = 1;
    }
    else if (errno != 0)
    {
        if (errno == ERANGE && *val == INT32_MIN)
        {
            cmsLog_error("%s errno ERANGE < INT32_MIN", __FUNCTION__);
        }
        else if (errno == ERANGE && *val == INT32_MAX)
        {
            cmsLog_error("%s errno ERANGE > INT32_MAX", __FUNCTION__);
        }
        else
        {
            cmsLog_error("%s errno %d", __FUNCTION__, errno);
            *val = 0;
        }
        ret = 1;
    }

    if (endptr != NULL)
    {
        *endptr = localEndPtr;
    }
    return ret;
}
/**
 * @brief Convert string to an unsigned integer with checks for errors
 *
 * @param num_str to convert to unsigned integer
 * @returns non zero on error
 */
int telem_strtoul(const char *num_str, char **endptr, int32_t base, uint32_t *val)
{
    int ret=0;
    char *localEndPtr=NULL;

    errno = 0;  /* set to 0 so we can detect ERANGE */

    /*
     * Linux strtoul allows a minus sign in front of the number.
     * This seems wrong to me.  Specifically check for this and reject
     * such strings.
     */
    while (isspace((unsigned char)*num_str))
    {
        num_str++;
    }

    if (*num_str == '-')
    {
        if (endptr)
        {
            *endptr = (char *) num_str;
        }
        errno = ERANGE;
        *val = 0;
    }
    else
    {
        *val = strtoul(num_str, &localEndPtr, base);
    }

    if (num_str == localEndPtr)
    {
        cmsLog_error("%s NaN: \"%s\"", __FUNCTION__, num_str);
        *val = 0;
        ret = 1;
    }
    else if (errno != 0)
    {
        if (errno == ERANGE && *val == 0)
        {
            cmsLog_error("%s errno ERANGE < 0", __FUNCTION__);
        }
        else if (errno == ERANGE && *val == UINT32_MAX)
        {
            cmsLog_error("%s errno ERANGE > UINT32_MAX", __FUNCTION__);
        }
        else
        {
            cmsLog_error("%s errno %d", __FUNCTION__, errno);
            *val = 0;
        }
        ret = 1;
    }

    if (endptr != NULL)
    {
        *endptr = localEndPtr;
    }

   return ret;
}

/**
 * @brief Convert string to an integer with checks for errors
 *
 * @param num_str to convert to integer
 * @returns non zero on error
 */
int telem_strtoll(const char *num_str, char **endptr, int32_t base, int64_t *val)
{
    int ret=0;
    char *localEndPtr=NULL;

    errno = 0;  /* set to 0 so we can detect ERANGE */

    *val = strtoll(num_str, &localEndPtr, base);

    if (num_str == localEndPtr)
    {
        cmsLog_error("%s NaN: \"%s\"", __FUNCTION__, num_str);
        *val = 0;
        ret = 1;
    }
    else if (errno != 0)
    {
        if (errno == ERANGE && *val == INT64_MIN)
        {
            cmsLog_error("%s errno ERANGE < INT64_MIN", __FUNCTION__);
        }
        else if (errno == ERANGE && *val == INT64_MAX)
        {
            cmsLog_error("%s errno ERANGE > INT64_MAX", __FUNCTION__);
        }
        else
        {
            cmsLog_error("%s errno %d", __FUNCTION__, errno);
            *val = 0;
        }
        ret = 1;
    }

    if (endptr != NULL)
    {
        *endptr = localEndPtr;
    }
    return ret;
}
/**
 * @brief Convert string to an unsigned integer with checks for errors
 *
 * @param num_str to convert to unsigned integer
 * @returns non zero on error
 */
int telem_strtoull(const char *num_str, char **endptr, int32_t base, uint64_t *val)
{
    int ret=0;
    char *localEndPtr=NULL;

    errno = 0;  /* set to 0 so we can detect ERANGE */

    /*
     * Linux strtoul allows a minus sign in front of the number.
     * This seems wrong to me.  Specifically check for this and reject
     * such strings.
     */
    while (isspace((unsigned char)*num_str))
    {
        num_str++;
    }

    if (*num_str == '-')
    {
        if (endptr)
        {
            *endptr = (char *) num_str;
        }
        errno = ERANGE;
        *val = 0;
    }
    else
    {
        *val = strtoull(num_str, &localEndPtr, base);
    }

    if (num_str == localEndPtr)
    {
        cmsLog_error("%s NaN: \"%s\"", __FUNCTION__, num_str);
        *val = 0;
        ret = 1;
    }
    else if (errno != 0)
    {
        if (errno == ERANGE && *val == 0)
        {
            cmsLog_error("%s errno ERANGE < 0", __FUNCTION__);
        }
        else if (errno == ERANGE && *val == UINT64_MAX)
        {
            cmsLog_error("%s errno ERANGE > UINT64_MAX", __FUNCTION__);
        }
        else
        {
            cmsLog_error("%s errno %d", __FUNCTION__, errno);
            *val = 0;
        }
        ret = 1;
    }

    if (endptr != NULL)
    {
        *endptr = localEndPtr;
    }

   return ret;
}

static int popen_get_int(char * command, void *value, int (*string_conv_fn)())
{
    int ret = 1;
    int status;
    FILE * fp = NULL;
    char output[BUFLEN_128]; // Big enough to store more than a 64 bit value in a string

    cmsLog_debug("command = \"%s\"",command);
    if ((fp = popen(command, "r")) != NULL)
    {
        if (fgets(output, BUFLEN_128, fp) != NULL)
        {
            if (strlen(output) > 0)
            {
                if((ret = string_conv_fn(output, NULL, 10 , value)) != 0)
                {
                    cmsLog_error("Command \"%s\" resulted in \"%s\"", command, output);
                }
            }
            else
            {
                cmsLog_error("Command \"%s\" resulted in no output", command);
            }
        }
        else
        {
            cmsLog_error("Command \"%s\" failed to execute", command);
        }

        fflush(fp);
        if ((status = status_checker(pclose(fp),command)) != 0)
        {
            ret = 1;
        }
    }

    return ret;
}