import * as React from "react";
import SunIcon from "./SunIcon";
import MoonIcon from "./MoonIcon";

const ThemeToggle: React.FC = () => {
  const [prefersDark, setPrefersDark] = React.useState<boolean>(false);
  const [theme, setTheme] = React.useState<string>(
    localStorage.getItem("theme") || (prefersDark ? "dark" : "light")
  );

  React.useEffect(() => {
    const mediaQuery = window.matchMedia("(prefers-color-scheme: dark)");
    const handleChange = (event: MediaQueryListEvent) => {
      setPrefersDark(event.matches);
    };

    setPrefersDark(mediaQuery.matches);
    mediaQuery.addEventListener("change", handleChange);

    return () => {
      mediaQuery.removeEventListener("change", handleChange);
    };
  }, []);

  React.useEffect(() => {
    localStorage.setItem("theme", theme);
  }, [theme]);

  function handleThemeChange() {
    const newTheme = theme === "dark" ? "light" : "dark";
    setTheme(newTheme);
  }

  return (
    <button
      className="theme-toggle"
      aria-label="Toggle theme"
      onClick={handleThemeChange}
    >
      <SunIcon />
      <MoonIcon />
    </button>
  );
};

export default ThemeToggle;
